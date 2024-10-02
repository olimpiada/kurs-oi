#!/bin/bash

# This script is used during `sinol-make verify` to stresstest the model solution
# against the brute-force solution. It generates tests by running `./abcingen stresstest $i`.
# You might need to customize the script for your task -- feel free to change anything.
# In particular, when in your task it's not possible to stresstest (like in interactive tasks),
# you can remove this script.

# Those are the default constants, but feel free to change when required.
# First `./$gen_filename stresstest $i` is being run to create a single test,
# then both the solution and slow solution is run and their output is compared.
script_name="$(basename "$0")"
task_id=${script_name:0:3} # It contains the tag of the task, e.g. `abc`.
gen_filename="${task_id}ingen.cpp"
sol_filename="${task_id}.cpp"
slo_filename="${task_id}s.cpp" # The main solution is tested against this brute-force solution.
chk_filename="${task_id}chk.cpp" # It ignores it when checker doesn't exist.
stresstest_seconds=10 # It stops running and creating tests after this amount of time, but it doesn't kill the solutions.

function compile_cpp {
    # The solutions are being manually compiled (`sinol-make` doesn't do it) and run normally, without oiejq.
    printf "Compiling %s...\n" "$1"
    g++ -std=c++20 -O3 -lm -Werror -Wall -Wextra -Wshadow -Wconversion -Wno-unused-result -Wfloat-equal "$1" -o "$2" \
        || exit 1
}
prog_dir="$(realpath "$(dirname "$0")")"
cache_dir="$prog_dir/../.cache"
mkdir -p "$cache_dir"
gen_exe="$cache_dir/${task_id}ingen"
sol_exe="$cache_dir/${task_id}solution"
slo_exe="$cache_dir/${task_id}slow"
chk_exe="$cache_dir/${task_id}chk"

compile_cpp "$prog_dir/${task_id}ingen.cpp" "$gen_exe"
compile_cpp "$prog_dir/${task_id}.cpp" "$sol_exe"
compile_cpp "$prog_dir/${task_id}s.cpp" "$slo_exe"
test -f "$prog_dir/${task_id}chk.cpp" && compile_cpp "$prog_dir/${task_id}chk.cpp" "$chk_exe"

for (( i=0, SECONDS=0; SECONDS < stresstest_seconds; i++ )); do
    in_test="$cache_dir/input.in"
    slo_out="$cache_dir/slo.out"
    sol_out="$cache_dir/sol.out"
    printf "Running stresstest $i [$SECONDS/${stresstest_seconds}s]\r"
    "$gen_exe" stresstest $i > "$in_test"     || { echo -e "\033[2KFailed to generate test $i";  exit 1; }
    "$slo_exe" < "$in_test" > "$slo_out"      || { echo -e "\033[2KBrute crashed on test $i";    exit 1; }
    "$sol_exe" < "$in_test" > "$sol_out"      || { echo -e "\033[2KSolution crashed on test $i"; exit 1; }

    if test -f "$prog_dir/${task_id}chk.cpp"; then
        chk_out="$cache_dir/chk.out"
        "$chk_exe" "$in_test" "$sol_out" "$slo_out" > "$chk_out" 2> /dev/null || { echo -e "\033[2KInvalid output on test $i"; cat "$chk_out"; exit 1; }
        test "$(cat "$chk_out" | head -n 1)" = "OK" || { echo -e "\033[2KInvalid output on test $i"; cat "$chk_out"; exit 1; }
        test "$(cat "$chk_out" | tail -n +3)" = "100" || { echo -e "\033[2KInvalid output on test $i"; cat "$chk_out"; exit 1; }
    else
        diff "$slo_out" "$sol_out" -w > /dev/null || { echo -e "\033[2KOutputs differ on test $i"; exit 1; }
    fi
done
echo -e "\033[2KStresstest passed with $i tests"
