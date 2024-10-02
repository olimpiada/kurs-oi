#include "oi.h"
#undef cout
#undef printf
#include <bits/stdc++.h>
using namespace std;

oi::Random rng;

const string task_id_str = "max";

// Change this function to generate one test for stresstesting.
// The script prog/abcingen.sh in 10 seconds generates as much tests as possible
// and compares the outputs of the model solution and brute solution.
// The tests shouldn't be very big, but should be able to cover edge cases.
void gen_stresstest() {
    int n = rng(1, 100);
    cout << n << '\n';
    for (int i = 0; i < n; ++i) {
        cout << rng(1,10000) << (i == n - 1 ? '\n' : ' ');
    }
}

void gen_proper_test(pair<int,int> n_r) {
    int n = n_r.first;
    int range = n_r.second;
    cout << n << '\n';
    for (int i = 0; i < n; ++i) {
        cout << rng(1,range) << (i == n - 1 ? '\n' : ' ');
    }
}

template<class Func, class... Args>
void gen_test(string test_name, uint_fast64_t seed, Func&& func, Args&&... args);

// If there's no need to set a specific seed, this function will reseed the `rng`
// with a deterministic hash of the `test_name` string.
template<class Func, class... Args>
void gen_test_reseed(string test_name, Func&& func, Args&&... args);

struct Test {
    unsigned group;
    unsigned id;

    operator string();
    Test operator++(int) noexcept;
    void advance_group() noexcept;
};

void gen_all_tests() {
//    gen_test_reseed("0", gen_0);
//    gen_test_reseed("1ocen", gen_1ocen);

    Test current_test{.group = 1, .id = 0};
    gen_test_reseed(current_test++, gen_proper_test, pair{1, 100});
    gen_test_reseed(current_test++, gen_proper_test, pair{10, 10});
    gen_test_reseed(current_test++, gen_proper_test, pair{23, 100});
    gen_test_reseed(current_test++, gen_proper_test, pair{49, 87});

    current_test.advance_group();
    gen_test_reseed(current_test++, gen_proper_test, pair{491, 101});
    gen_test_reseed(current_test++, gen_proper_test, pair{999, 10'000});
    gen_test_reseed(current_test++, gen_proper_test, pair{1'000, 1982});
    gen_test_reseed(current_test++, gen_proper_test, pair{1'000, 100'000});

    current_test.advance_group();
    gen_test_reseed(current_test++, gen_proper_test, pair{999'999, 100'000});
    gen_test_reseed(current_test++, gen_proper_test, pair{1'000'000, 100'000});
    gen_test_reseed(current_test++, gen_proper_test, pair{1'000'000, 31415});
    gen_test_reseed(current_test++, gen_proper_test, pair{1'000'000, 981});

}

int main(int argc, char* argv[]) {
    if (argc == 3 && string(argv[1]) == "stresstest") {
        // Usage: prog/*ingen stresstest seed_uint64
        rng = oi::Random{static_cast<uint_fast64_t>(stoll(argv[2]))};
        gen_stresstest();
        return 0;
    }
    oi_assert(argc == 1, "Run prog/*ingen.sh to stresstest and create proper tests.");
    gen_all_tests();
    return 0;
}

///////////////////// `Test` and `gen_test_reseed` implementation /////////////////////

const string& get_task_id() {
    static auto task_id = [](string path) {
        auto end = path.rfind("ingen.");
        oi_assert(end != string::npos);
        auto beg = path.rfind('/', end);
        if (beg == string::npos) {
            beg = 0;
        } else {
            ++beg;
        }
        return path.substr(beg, end - beg);
    }(__FILE__);
    return task_id;
}

template<class Func, class... Args>
void gen_test(string test_name, uint_fast64_t seed, Func&& func, Args&&... args) {
    // Flush the buffers before reopening the next test.
    cout << flush;
    fflush(stdout);
    auto test_filename = task_id_str + test_name + ".in";
    oi_assert(freopen(test_filename.c_str(), "w", stdout), "failed to save test ", test_filename);
    std::cerr << "Generating " << test_filename << "...\n";
    rng = oi::Random{seed};
    func(std::forward<decltype(args)>(args)...);
    // Flush the buffers before giving up control to the caller.
    cout << flush;
    fflush(stdout);
}

template<class Func, class... Args>
void gen_test_reseed(string test_name, Func&& func, Args&&... args) {
    // The new seed is created from the test name.
    uint_fast64_t seed = static_cast<uint_fast64_t>(hash<string_view>{}(test_name));
    gen_test(test_name, seed, func, args...);
}

Test::operator string() {
    string res = "";
    for (;;) {
        res += static_cast<char>('a' + id % ('z' - 'a' + 1));
        if (id <= 'z' - 'a') {
            break;
        }
        id = id / ('z' - 'a' + 1) - 1;
    }
    std::reverse(res.begin(), res.end());
    return to_string(group) + res;
}

Test Test::operator++(int) noexcept {
    Test res = *this;
    ++id;
    return res;
}

void Test::advance_group() noexcept {
    ++group;
    id = 0;
}
