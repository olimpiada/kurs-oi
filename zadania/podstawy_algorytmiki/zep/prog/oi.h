// oi.h - biblioteka do pisania sprawdzania wejsc (inwer), wyjsc (chk) oraz generowania testow (ingen).
// Author: Krzysztof Małysa.
// In case of problems or improvements, please open an issue / merge request:
// https://sinol3.dasie.mimuw.edu.pl/sinol3/template-package

#pragma once

#include <algorithm>
#include <array>
#include <cassert>
#include <cctype>
#include <cerrno>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <cstdio> // to prevent messing <cstdio> after forbidding scanf(), printf(), fopen() by macro
#include <cstdlib> // to prevent messing <cstdlib> after forbidding exit() and _Exit() by macro
#include <cstring>
#include <fcntl.h>
#include <exception>
#include <fstream> // to prevent messing <fstream> after forbidding ifstream and fstream by macro
#include <iostream> // to prevent messing <iostream> after forbidding cin is forbidden by macro
#include <limits>
#include <optional>
#include <random>
#include <set>
#include <sstream>
#include <string>
#include <string_view>
#include <sys/mman.h>
#include <sys/resource.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <type_traits>
#include <unistd.h> // to prevent messing <unistd.h> after forbidding _exit() by macro
#include <utility>
#include <vector>

using std::string;
using std::vector;

namespace oi {

class CheckerVerdict {
    std::optional<int> partial_score = std::nullopt;
    string partial_score_msg;

public:
    // 100% points
    [[noreturn]] void exit_ok();

    // score * 1% points
    template <class... Msg>
    [[noreturn]] void exit_ok_with_score(int score, Msg&&... msg);

    template<class... Msg>
    void set_partial_score(int score, Msg&&... msg);

    // If partial score is set, then partial_score * 1% points, 0% points otherwise
    template <class... Msg>
    [[noreturn]] void exit_wrong(Msg&&... msg);

} inline checker_verdict;

struct InwerVerdict {
    struct Stream {
        int exit_code;

        struct StreamImpl {
            int exit_code;
            bool printed = false;

            ~StreamImpl();

            template<class T>
            StreamImpl& operator<<(T&& arg);
        };

        StreamImpl operator()();
    };

    // Use like cout: oi::inwer_verdict.exit_ok() << "some comment";
    // Exits the program with 0, after printing the comment.
    Stream exit_ok{0};

    // Use like cout: oi::inwer_verdict.exit_wrong() << "some comment";
    // Exits the program with 1, after printing the comment.
    Stream exit_wrong{1};
} inline inwer_verdict;

template <class... Msg>
[[noreturn]] void bug(Msg&&... msg);

#define oi_assert(condition, ...)                                          \
    ((condition) ? (void)0 : [func = __PRETTY_FUNCTION__](auto&&... msg) { \
        ::oi::detail::exit_with_error_msg(                                 \
            3,                                                             \
            __FILE__ ":",                                                  \
            __LINE__,                                                      \
            ": ",                                                          \
            func,                                                          \
            ": Assertion `" #condition "` failed",                         \
            (sizeof...(msg) == 0 ? "." : ": "),                            \
            std::forward<decltype(msg)>(msg)...                            \
        );                                                                 \
    }(__VA_ARGS__))


enum class Lang {
    EN = 0,
    PL = 1,
};

struct EofType {
} eof;

struct NlType {
} nl;

struct IgnoreWsType {
} ignore_ws; // ignore every whitespace including newline

struct Line {
    string& var;
    size_t max_size;

    Line(string& var_, size_t max_size_) : var{var_}, max_size{max_size_} {}
};

struct Str {
    string& var;
    size_t max_size;

    Str(string& var_, size_t max_size_) : var{var_}, max_size{max_size_} { assert(max_size_ > 0); }
};

struct Char {
    char& var;
    const char* variants;

    Char(char& var_, const char* variants_) : var{var_}, variants{variants_} {}
};

template <class T>
struct Num {
    T& var;
    T min, max; // inclusive

    Num(T& var_, T min_, T max_) : var{var_}, min{min_}, max{max_} { assert(min <= max); }
};

template <class A, class B, class C>
Num(A, B, C) -> Num<A>;

class Scanner {
public:
    enum class Mode {
        UserOutput, // eof ignores newline and whitespace, nl ignores whitespace, destructor scans
                    // eof
        Lax, // eof ignores newline and whitespace, nl ignores whitespace, destructor does nothing
        TestInput, // eof DOES NOT ignore newline or whitespace, nl DOES NOT ignore whitespace,
                   // destructor scans eof
    };

    Scanner(FILE* file_, Mode mode_, Lang lang_);
    Scanner(const char* file_path, Mode mode_, Lang lang_);

    ~Scanner();

    template <class... Msg>
    [[noreturn]] void error(Msg&&... msg);

    Scanner& operator>>(const char& c);
    Scanner& operator>>(EofType /*unused*/);
    Scanner& operator>>(NlType /*unused*/);
    Scanner& operator>>(IgnoreWsType /*unused*/);

    // Reads line without the trailing newline character.
    // Use like this: scanner >> Line{s, 1000}
    Scanner& operator>>(Line line);

    // Use like this: scanner >> Str{s, 1000}
    Scanner& operator>>(Str str);

    // Use like this: scanner >> Char{c, "TN"}
    Scanner& operator>>(Char chr);

    // Use like this: scanner >> Num{x, -1000, 1000}
    // Works with double too: scanner >> Num{x, -3.14, 3.14}
    template <class T>
    Scanner& operator>>(Num<T> num);

    Scanner(const Scanner&) = delete;
    Scanner(Scanner&&) = delete;
    Scanner& operator=(const Scanner&) = delete;
    Scanner& operator=(Scanner&&) = delete;

    template <class...>
    static constexpr inline bool always_false = false;

    template <class T> requires std::is_same_v<T, char&> ||
                (std::is_convertible_v<T&&, char> &&
                 !std::is_same_v<std::remove_const_t<std::remove_reference_t<T>>, char>)
    Scanner& operator>>(T&& /*unused*/) {
        static_assert(
            always_false<T>,
            R"(Use Num{}, Char{} or Str{} e.g. scanner >> Num{x, 0, 42} >> Char{c, "TN"} >> Str{s, 100};)"
        );
        return *this;
    }

    void do_destructor_checks();

protected:
    FILE* file;
    FILE* owned_file = nullptr;
    Mode mode;
    Lang lang;

    struct Pos {
        size_t line;
        size_t pos;
    };

    Pos next_char_pos = {.line = 1, .pos = 1};
    Pos last_char_pos = {.line = 1, .pos = 1};
    Pos prev_last_char_pos = {.line = 1, .pos = 1};
    bool eofed = false;

    std::optional<int> next_char;

    bool getchar(int& ch) noexcept; // returns true if not eofed
    void ungetchar(int ch) noexcept;
    static string char_description(int ch);

    template <class T>
    void scan_integer(T& val);

    template <class T>
    void scan_floating_point(T& val);
};

class Random {
public:
    explicit Random(uint_fast64_t seed = 5489);

    template <class T> requires std::is_arithmetic_v<T>
    T operator()(T min, T max);

    template <class RandomAccessIterator>
    void shuffle(RandomAccessIterator begin, RandomAccessIterator end);

    template <class T>
    void shuffle(T& container) {
        shuffle(container.begin(), container.end());
    }

    Random(const Random&) = delete;
    Random(Random&&) = default;
    Random& operator=(const Random&) = delete;
    Random& operator=(Random&&) = default;

private:
    std::mt19937_64 generator;
};

struct TestInput {
    string str;

    explicit TestInput(string str_) : str{std::move(str_)} {}
};

struct TestOutput {
    string str;

    explicit TestOutput(string str_) : str{std::move(str_)} {}
};

struct UserOutput {
    string str;

    explicit UserOutput(string str_) : str{std::move(str_)} {}
};

struct CheckerOutput {
    string str;

    explicit CheckerOutput(string str_) : str{std::move(str_)} {}
};

} // namespace oi

#define CONCAT_RAW(a, b) a##b
#define CONCAT(a, b) CONCAT_RAW(a, b)
#define CHECKER_TEST(...)                                                             \
    namespace {                                                                       \
    __attribute__((constructor)) void CONCAT(checker_test_constructor_, __LINE__)() { \
        ::oi::detail::get_checker_test_fns().emplace_back([] {                        \
            using oi::CheckerOutput;                                                  \
            using oi::TestInput;                                                      \
            using oi::TestOutput;                                                     \
            using oi::UserOutput;                                                     \
            ::oi::detail::checker_test(                                               \
                string{__FILE__ ":"} + std::to_string(__LINE__), __VA_ARGS__          \
            );                                                                        \
        });                                                                           \
    }                                                                                 \
    }

//////////////////////////////// Implementation ////////////////////////////////

namespace oi {

inline std::set<Scanner*>& get_all_scanners() noexcept {
    static std::set<Scanner*> scanners;
    [[maybe_unused]] static bool x = [] {
        void (*func)() = [] {
            // To succeed, the destructor checks have to pass
            for (auto* scanner : get_all_scanners()) {
                scanner->do_destructor_checks();
            }
        };
        if (atexit(func)) {
            std::terminate();
        }
        return true;
    }();
    return scanners;
}

[[noreturn]] inline void CheckerVerdict::exit_ok() {
    // To get the whole score, the destructor checks have to pass
    for (auto* scanner : get_all_scanners()) {
        scanner->do_destructor_checks();
    }
    std::cout << "OK\n\n100\n" << std::flush;
    _exit(0);
}

template <class... Msg>
[[noreturn]] void CheckerVerdict::exit_ok_with_score(int score, Msg&&... msg) {
    assert(0 <= score && score <= 100);
    if (score == 100) {
        // To get the whole score, the destructor checks have to pass
        for (auto* scanner : get_all_scanners()) {
            scanner->do_destructor_checks();
        }
    }
    std::cout << "OK\n";
    (std::cout << ... << std::forward<Msg>(msg)) << '\n';
    std::cout << score << '\n' << std::flush;
    _exit(0);
}

template<class... Msg>
inline void CheckerVerdict::set_partial_score(int score, Msg&&... msg) {
    assert(0 <= score && score < 100);
    partial_score = score;

    std::stringstream ss;
    (ss << ... << std::forward<Msg>(msg));
    partial_score_msg = std::move(ss).str();
}

template <class... Msg>
[[noreturn]] void CheckerVerdict::exit_wrong(Msg&&... msg) {
    if (partial_score) {
        std::cout << "OK\n";
        std::cout << partial_score_msg;
        if (!partial_score_msg.empty() && sizeof...(msg) != 0) {
            std::cout << "; ";
        }
        (std::cout << ... << std::forward<Msg>(msg)) << '\n';
        std::cout << *partial_score << '\n' << std::flush;
    } else {
        std::cout << "WRONG\n";
        (std::cout << ... << std::forward<Msg>(msg)) << '\n';
        std::cout << "0\n" << std::flush;
    }
    _exit(0);
}

InwerVerdict::Stream::StreamImpl InwerVerdict::Stream::operator()() {
    if (exit_code == 0) {
        // To pass the input verification, the destructor checks have to pass
        for (auto* scanner : get_all_scanners()) {
            scanner->do_destructor_checks();
        }
    }
    return StreamImpl{exit_code};
}

template<class T>
InwerVerdict::Stream::StreamImpl& InwerVerdict::Stream::StreamImpl::operator<<(T&& arg) {
    printed = true;
    std::cout << std::forward<T>(arg);
    return *this;
}

InwerVerdict::Stream::StreamImpl::~StreamImpl() {
    if (printed) {
        std::cout << '\n';
    }
    std::cout << std::flush;
    _exit(exit_code);
}

namespace detail {

std::ostream*& get_error_ostream() noexcept {
    static auto* kind = &std::cerr;
    return kind;
}

void change_error_ostream_to_cout() noexcept {
    get_error_ostream() = &std::cout;
}

template <class... Msg>
[[noreturn]] void exit_with_error_msg(int exit_code, Msg&&... msg) {
    (*get_error_ostream() << ... << std::forward<Msg>(msg)) << '\n' << std::flush;
    _exit(exit_code);
}

} // namespace detail

template <class... Msg>
[[noreturn]] void bug(Msg&&... msg) {
    detail::exit_with_error_msg(2, "BUG: ", std::forward<Msg>(msg)...);
}

inline Scanner::Scanner(FILE* file_, Mode mode_, Lang lang_)
: file{file_}
, mode{mode_}
, lang{lang_} {
    get_all_scanners().emplace(this);
}

inline Scanner::Scanner(const char* file_path, Mode mode_, Lang lang_)
: file{[file_path] {
    FILE* f = fopen(file_path, "r");
    if (!f) {
        bug("fopen() failed - ", strerror(errno));
    }
    return f;
}()}
, owned_file{file}
, mode{mode_}
, lang{lang_} {
    get_all_scanners().emplace(this);
}

inline Scanner::~Scanner() {
    do_destructor_checks();

    get_all_scanners().erase(this);
    if (owned_file) {
        (void)fclose(owned_file);
    }
}

template <class... Msg>
[[noreturn]] void do_error(Scanner::Mode mode, Msg&&... msg) {
    switch (mode) {
    case Scanner::Mode::UserOutput: checker_verdict.exit_wrong(std::forward<Msg>(msg)...);
    case Scanner::Mode::Lax: detail::exit_with_error_msg(4, "Lax scanner: ", std::forward<Msg>(msg)...);
    case Scanner::Mode::TestInput:
        (inwer_verdict.exit_wrong() << ... << std::forward<Msg>(msg));
    }
    __builtin_unreachable();
}

template <class... Msg>
[[noreturn]] void Scanner::error(Msg&&... msg) {
    switch (lang) {
    case Lang::EN:
        do_error(
            mode,
            "Line ",
            last_char_pos.line,
            ", position ",
            last_char_pos.pos,
            ": ",
            std::forward<Msg>(msg)...
        );
    case Lang::PL:
        do_error(
            mode,
            "Wiersz ",
            last_char_pos.line,
            ", pozycja ",
            last_char_pos.pos,
            ": ",
            std::forward<Msg>(msg)...
        );
    }
    __builtin_unreachable();
}

constexpr const char* read_eof_expected_a_string[] = {
    "Read EOF, expected a string",
    "Wczytano EOF, oczekiwano napisu",
};
constexpr const char* too_long_string[] = {
    "Too long string",
    "Zbyt dlugi napis",
};
constexpr const char* read_eof_expected_a_number[] = {
    "Read EOF, expected a number",
    "Wczytano EOF, oczekiwano liczby",
};
constexpr const char* read_minus_expected_a_positive_number[] = {
    "Read '-', expected a non-negative number",
    "Wczytano '-', oczekiwano nieujemnej liczby",
};
constexpr const char* integer_value_out_of_range[] = {
    "Integer value out of range",
    "Liczba calkowita spoza zakresu",
};
constexpr const char* real_number_value_out_of_range[] = {
    "Real number value out of range",
    "Liczba rzeczywista spoza zakresu",
};

inline Scanner& Scanner::operator>>(const char& c) {
    int ch = 0;
    if (!getchar(ch)) {
        switch (lang) {
        case Lang::EN: error("Read EOF, expected ", char_description(c));
        case Lang::PL: error("Wczytano EOF, oczekiwano ", char_description(c));
        }
    }
    if (ch != c) {
        switch (lang) {
        case Lang::EN: error("Read ", char_description(ch), ", expected ", char_description(c));
        case Lang::PL:
            error("Wczytano ", char_description(ch), ", oczekiwano ", char_description(c));
        }
    }
    return *this;
}

inline Scanner& Scanner::operator>>(EofType /*unused*/) {
    int ch = 0;
    switch (mode) {
    case Mode::UserOutput:
    case Mode::Lax: {
        // Ignore whitespace including newline
        for (;;) {
            if (!getchar(ch)) {
                return *this;
            }
            if (!isspace(ch)) {
                ungetchar(ch);
                break;
            }
        }
    } break;
    case Mode::TestInput: break;
    }

    if (getchar(ch)) {
        switch (lang) {
        case Lang::EN: error("Read ", char_description(ch), ", expected EOF");
        case Lang::PL: error("Wczytano ", char_description(ch), ", oczekiwano EOF");
        }
    }
    return *this;
}

inline Scanner& Scanner::operator>>(NlType /*unused*/) {
    switch (mode) {
    case Mode::UserOutput:
    case Mode::Lax: {
        *this >> ignore_ws;
    } break;
    case Mode::TestInput: break;
    }
    return *this >> '\n';
}

inline Scanner& Scanner::operator>>(IgnoreWsType /*unused*/) {
    int ch = 0;
    for (;;) {
        if (!getchar(ch)) {
            ungetchar(EOF);
            break;
        }
        if (ch == '\n' || !isspace(ch)) {
            ungetchar(ch);
            break;
        }
    }
    return *this;
}

inline Scanner& Scanner::operator>>(Line line) {
    line.var.clear();
    int ch = 0;
    for (;;) {
        if (!getchar(ch)) {
            ungetchar(EOF);
            break;
        }
        if (ch == '\n') {
            ungetchar(ch);
            break;
        }
        line.var += static_cast<char>(ch);
    }
    return *this;
}

inline Scanner& Scanner::operator>>(Str str) {
    str.var.clear();
    int ch = 0;
    if (!getchar(ch)) {
        error(read_eof_expected_a_string[static_cast<int>(lang)]);
    }
    if (isspace(ch)) {
        switch (lang) {
        case Lang::EN: error("Read ", char_description(ch), ", expected a string");
        case Lang::PL: error("Wczytano ", char_description(ch), ", oczekiwano napisu");
        }
    }

    for (;;) {
        str.var += static_cast<char>(ch);
        if (str.var.size() > str.max_size) {
            error(too_long_string[static_cast<int>(lang)]);
        }

        if (!getchar(ch)) {
            ungetchar(EOF);
            break;
        }
        if (isspace(ch)) {
            ungetchar(ch);
            break;
        }
    }
    return *this;
}

inline Scanner& Scanner::operator>>(Char chr) {
    int ch = 0;
    if (!getchar(ch)) {
        switch (lang) {
        case Lang::EN: error("Read EOF, expected one of characters: ", chr.variants);
        case Lang::PL: error("Wczytano EOF, oczekiwano jednego ze znakow: ", chr.variants);
        }
    }
    if (strchr(chr.variants, ch) == nullptr) {
        switch (lang) {
        case Lang::EN:
            error("Read ", char_description(ch), ", expected one of characters: ", chr.variants);
        case Lang::PL:
            error(
                "Wczytano ", char_description(ch), ", oczekiwano jednego ze znakow: ", chr.variants
            );
        }
    }
    chr.var = static_cast<char>(ch);
    return *this;
}

template <class T>
inline Scanner& Scanner::operator>>(Num<T> num) {
    if constexpr (std::is_integral_v<T>) {
        scan_integer(num.var);
        if (num.var < num.min || num.var > num.max) {
            error(integer_value_out_of_range[static_cast<int>(lang)]);
        }
    } else {
        scan_floating_point(num.var);
        if (num.var < num.min || num.var > num.max) {
            error(real_number_value_out_of_range[static_cast<int>(lang)]);
        }
    }
    return *this;
}

inline bool Scanner::getchar(int& ch) noexcept {
    if (eofed) {
        return false;
    }

    if (next_char) {
        ch = *next_char;
        next_char = std::nullopt;
    } else {
        ch = getc_unlocked(file);
    }
    eofed = (ch == EOF);
    prev_last_char_pos = last_char_pos;
    last_char_pos = next_char_pos;
    if (ch == '\n') {
        ++next_char_pos.line;
        next_char_pos.pos = 1;
    } else {
        ++next_char_pos.pos;
    }
    return !eofed;
}

inline void Scanner::ungetchar(int ch) noexcept {
    assert(!next_char && "cannot ungetchar() more than one without getchar()");
    next_char = ch;
    next_char_pos = last_char_pos;
    last_char_pos = prev_last_char_pos;
    eofed = false;
}

inline string Scanner::char_description(int ch) {
    if (std::isgraph(ch)) {
        return {'\'', static_cast<char>(ch), '\''};
    }

    if (ch == ' ') {
        return "' '";
    }
    if (ch == '\n') {
        return "'\\n'";
    }
    if (ch == '\r') {
        return "'\\r'";
    }
    if (ch == '\t') {
        return "'\\t'";
    }
    if (ch == '\0') {
        return "'\\0'";
    }

    constexpr char digits[] = "0123456789abcdef";
    return {'\'', '\\', 'x', digits[ch >> 4], digits[ch & 15], '\''};
}

template <class T>
void Scanner::scan_integer(T& val) {
    static_assert(std::is_integral_v<T>);
    int ch = 0;
    if (!getchar(ch)) {
        error(read_eof_expected_a_number[static_cast<int>(lang)]);
    }

    bool minus = false;
    if (ch == '-') {
        if (std::is_unsigned_v<T>) {
            error(read_minus_expected_a_positive_number[static_cast<int>(lang)]);
        }
        minus = true;
        if (!getchar(ch)) {
            error(read_eof_expected_a_number[static_cast<int>(lang)]);
        }
    }

    if (ch < '0' || '9' < ch) {
        switch (lang) {
        case Lang::EN: error("Read ", char_description(ch), ", expected a number");
        case Lang::PL: error("Wczytano ", char_description(ch), ", oczekiwano liczby");
        }
    }

    val = static_cast<T>(minus ? '0' - ch : ch - '0'); // Will not overflow
    for (;;) {
        if (!getchar(ch)) {
            ungetchar(EOF);
            break;
        }
        if (!isdigit(ch)) {
            ungetchar(ch);
            break;
        }

        if (__builtin_mul_overflow(val, 10, &val)) {
            error(integer_value_out_of_range[static_cast<int>(lang)]);
        }
        if (!minus && __builtin_add_overflow(val, ch - '0', &val)) {
            error(integer_value_out_of_range[static_cast<int>(lang)]);
        }
        if (minus && __builtin_sub_overflow(val, ch - '0', &val)) {
            error(integer_value_out_of_range[static_cast<int>(lang)]);
        }
    }
}

template <class T>
void Scanner::scan_floating_point(T& val) {
    static_assert(std::is_floating_point_v<T>);
    int ch = 0;
    if (!getchar(ch)) {
        error(read_eof_expected_a_number[static_cast<int>(lang)]);
    }

    bool minus = false;
    if (ch == '-') {
        minus = true;
        if (!getchar(ch)) {
            error(read_eof_expected_a_number[static_cast<int>(lang)]);
        }
    }

    if (ch < '0' || '9' < ch) {
        switch (lang) {
        case Lang::EN: error("Read ", char_description(ch), ", expected a number");
        case Lang::PL: error("Wczytano ", char_description(ch), ", oczekiwano liczby");
        }
    }

    val = (minus ? '0' - ch : ch - '0'); // Will not overflow
    for (;;) {
        if (!getchar(ch)) {
            ungetchar(EOF);
            return;
        }
        if (ch == '.') {
            break;
        }
        if (!isdigit(ch)) {
            ungetchar(ch);
            return;
        }
        val *= 10;
        if (!minus) {
            val += ch - '0';
        } else {
            val -= ch - '0';
        }
        if (std::isinf(val)) {
            error(real_number_value_out_of_range[static_cast<int>(lang)]);
        }
    }

    T pow10 = 1;
    T subpoint = 0;
    for (;;) {
        if (!getchar(ch)) {
            ungetchar(EOF);
            break;
        }
        if (!isdigit(ch)) {
            ungetchar(ch);
            break;
        }
        pow10 *= 0.1;
        subpoint += pow10 * (ch - '0');
    }
    if (!minus) {
        val += subpoint;
    } else {
        val -= subpoint;
    }
    if (std::isinf(val)) {
        error(real_number_value_out_of_range[static_cast<int>(lang)]);
    }
}

inline void Scanner::do_destructor_checks() {
    switch (mode) {
    case Mode::UserOutput:
    case Mode::TestInput: {
        *this >> eof;
    } break;
    case Mode::Lax: break;
    }
}

inline Random::Random(uint_fast64_t seed) : generator{seed} {}

template <class T> requires std::is_arithmetic_v<T>
T Random::operator()(T min, T max) {
    oi_assert(min <= max);
    constexpr auto generator_range_len = decltype(generator)::max() - decltype(generator)::min();
    if constexpr (std::is_floating_point_v<T>) {
        auto val = generator() - decltype(generator)::min(); // in range [0, generator_range_len]
        T scaled_val = static_cast<T>(val) / static_cast<T>(generator_range_len); // in range [0, 1]
        return scaled_val * (max - min) + min;
    } else if constexpr (std::is_unsigned_v<T>) {
        auto range_len = static_cast<uint_fast64_t>(max) - static_cast<uint_fast64_t>(min) + 1;
        if (range_len == 0) { // max range
            return static_cast<T>(generator());
        }
        auto limit = generator_range_len - generator_range_len % range_len;
        for (;;) {
            auto val =
                generator() - decltype(generator)::min(); // in range [0, generator_range_len]
            // We want val to be in range [0, generator_range_len - generator_range_len % range_len
            // - 1]
            // <=> val < generator_range_len - generator_range_len % range_len
            if (val >= limit) {
                continue;
            }
            return static_cast<T>(val % range_len) + min;
        }
    } else {
        using UT = std::make_unsigned_t<T>;
        // Shift [min, max] to [umin, umax], where umin >= 0
        UT umin = static_cast<UT>(min) - static_cast<UT>(std::numeric_limits<T>::min());
        UT umax = static_cast<UT>(max) - static_cast<UT>(std::numeric_limits<T>::min());
        UT val = this->operator()<UT>(umin, umax) + static_cast<UT>(std::numeric_limits<T>::min());
        return static_cast<T>(val);
    }
}

template <class RandomAccessIterator>
void Random::shuffle(RandomAccessIterator begin, RandomAccessIterator end) {
    for (auto i = end - begin; i > 1;) {
        --i;
        std::swap(begin[i], begin[this->operator()<decltype(i)>(0, i)]);
    }
}

} // namespace oi

namespace oi::detail {

inline std::vector<void (*)()>& get_checker_test_fns() {
    static std::vector<void (*)()> test_fns;
    return test_fns;
}

} // namespace oi::detail

int the_only_real_true_main(int, char**);

namespace oi::detail {

inline void checker_test(
    const string& test_name,
    TestInput test_input,
    TestOutput test_output,
    UserOutput user_output,
    CheckerOutput checker_output
) {
    auto terminate_with_error = [test_name](auto&&... msg) {
        ::oi::detail::exit_with_error_msg(
            5, "Checker test ", test_name, " failed: ", std::forward<decltype(msg)>(msg)...
        );
    };

    auto create_fd = [&terminate_with_error] {
        // Using tmpfile() to be POSIX compliant, so that it works on MacOS.
        auto* f = tmpfile();
        if (!f) {
            terminate_with_error("tmpfile() - ", strerror(errno));
        }
        int fd = dup(fileno(f));
        if (fclose(f)) {
            terminate_with_error("flose() - ", strerror(errno));
        }
        return fd;
    };

    auto create_fd_with_contents = [&terminate_with_error, &create_fd](const string& contents) {
        auto fd = create_fd();
        if (pwrite(fd, contents.data(), contents.size(), 0) !=
            static_cast<ssize_t>(contents.size()))
        {
            terminate_with_error("pwrite() - ", strerror(errno));
        }
        return fd;
    };

    int in_fd = create_fd_with_contents(test_input.str);
    int out_fd = create_fd_with_contents(test_output.str);
    int user_out_fd = create_fd_with_contents(user_output.str);

    int checker_out_fd = create_fd();

    int pid = fork();
    if (pid == -1) {
        terminate_with_error("fork() - ", strerror(errno));
    }
    if (pid == 0) {
        (void)freopen("/dev/null", "r", stdin);
        if (dup2(checker_out_fd, STDOUT_FILENO) != STDOUT_FILENO) {
            terminate_with_error("dup2() - ", strerror(errno));
        }

        char prog_name[] = "";
        auto test_input_path = string{"/dev/fd/"} + std::to_string(in_fd);
        auto test_output_path = string{"/dev/fd/"} + std::to_string(out_fd);
        auto user_output_path = string{"/dev/fd/"} + std::to_string(user_out_fd);

        char* argv[] = {
            prog_name,
            test_input_path.data(),
            user_output_path.data(),
            test_output_path.data(),
            nullptr,
        };
        exit(the_only_real_true_main(4, argv));
    }
    (void)close(user_out_fd);
    (void)close(out_fd);
    (void)close(in_fd);

    int status;
    if (waitpid(pid, &status, 0) != pid) {
        terminate_with_error("waitpid() - ", strerror(errno));
    }

    std::string captured_output;
    std::array<char, 4096> buff;
    for (off_t offset = 0;;) {
        auto rc = pread(checker_out_fd, buff.data(), buff.size(), offset);
        if (rc > 0) {
            offset += rc;
            captured_output.append(buff.data(), static_cast<size_t>(rc));
            continue;
        }
        if (rc == 0) {
            break;
        }
        terminate_with_error("pread() - ", strerror(errno));
    }
    (void)close(checker_out_fd);

    if (!WIFEXITED(status)) {
        terminate_with_error("checker program crashed with output:\n", captured_output);
    }

    int exit_code = WEXITSTATUS(status);
    if (exit_code != 0) {
        terminate_with_error(
            "checker program exited with ", exit_code, " with output:\n", captured_output
        );
    }
    if (captured_output != checker_output.str) {
        terminate_with_error(
            "checker program exited with 0 with output:\n",
            captured_output,
            "\nexpected it to exit with 0 and output:\n",
            checker_output.str
        );
    }
}

inline void checker_test(const string &test_name, const string& data) {
    constexpr std::string_view test_in_str = "@test_in\n";
    constexpr std::string_view test_out_str = "@test_out\n";
    constexpr std::string_view user_str = "@user\n";
    constexpr std::string_view checker_str = "@checker\n";
    auto find_beg_of = [&data](std::string_view delim, size_t start_pos) -> size_t {
        auto delim_pos = data.find(delim, start_pos);
        if (delim_pos == string::npos) {
            oi::bug("Could not find ", delim, " in the test string");
        }
        return delim_pos + delim.size();
    };

    auto test_in_beg = find_beg_of(test_in_str, 0);
    auto test_out_beg = find_beg_of(test_out_str, test_in_beg);
    auto user_beg = find_beg_of(user_str, test_out_beg);
    auto checker_beg = find_beg_of(checker_str, user_beg);
    checker_test(
        test_name,
        TestInput{string{
            data.begin() + static_cast<ssize_t>(test_in_beg),
            data.begin() + static_cast<ssize_t>(test_out_beg - test_out_str.size())
        }},
        TestOutput{string{
            data.begin() + static_cast<ssize_t>(test_out_beg),
            data.begin() + static_cast<ssize_t>(user_beg - user_str.size())
        }},
        UserOutput{string{
            data.begin() + static_cast<ssize_t>(user_beg),
            data.begin() + static_cast<ssize_t>(checker_beg - checker_str.size())
        }},
        CheckerOutput{data.substr(checker_beg)}
    );
}

inline bool we_are_running_on_sio2() {
    auto user_str = getenv("USER");
    return user_str != nullptr && std::string_view{user_str} == "oioioiworker";
}

} // namespace oi::detail

#define main(...)                                                                              \
    the_only_real_true_main(__VA_ARGS__);                                                      \
    /* Before checker_test(), the_only_real_true_main() is declared as: */                     \
    /* int the_only_real_true_main(int, char**); */                                            \
    /* it overloads the_only_real_true_main() in case __VA_ARGS__ is empty, */                 \
    /* hence the workaround */                                                                 \
    int only_for_type_deduction_main(__VA_ARGS__);                                             \
                                                                                               \
    int main(int argc, char** argv) {                                                          \
        auto filename = std::string_view{__FILE__};                                            \
        /* Remove the extension */                                                             \
        while (!filename.empty() && filename.back() != '.') {                                  \
            filename.remove_suffix(1);                                                         \
        }                                                                                      \
        if (filename.ends_with("chk.")) {                                                      \
            ::oi::detail::change_error_ostream_to_cout();                                      \
        }                                                                                      \
                                                                                               \
        if (!::oi::detail::we_are_running_on_sio2() &&                                         \
            !oi::detail::get_checker_test_fns().empty())                                       \
        {                                                                                      \
            std::cerr << "Running " << oi::detail::get_checker_test_fns().size()               \
                      << " checker tests...\n";                                                \
            for (auto checker_test_fn : ::oi::detail::get_checker_test_fns()) {                \
                checker_test_fn();                                                             \
            }                                                                                  \
            std::cerr << "All tests passed.\n";                                                \
        }                                                                                      \
                                                                                               \
        return [&](auto main_func) {                                                           \
            /* We need main_func in the branches to be template-dependent, hence the lambda */ \
            if constexpr (std::is_convertible_v<decltype(main_func), int (*)()>) {             \
                return main_func();                                                            \
            } else {                                                                           \
                return main_func(argc, argv);                                                  \
            }                                                                                  \
        }(static_cast<decltype(&only_for_type_deduction_main)>(&the_only_real_true_main));     \
    }                                                                                          \
    int the_only_real_true_main(__VA_ARGS__)

///////////////// FORBIDDING MACROS /////////////////
#define cin                                                         \
    cin;                                                            \
    static_assert(false, "Don't use cin, use oi::Scanner instead"); \
    ::std::cin
#define cout cout; static_assert(false, "Don't use cout, use oi::checker_verdict or oi::inwer_verdict instead or oi::bug()"); ::std::cout
#define fstream                                                         \
    fstream;                                                            \
    static_assert(false, "Don't use fstream, use oi::Scanner instead"); \
    ::std::fstream
#define ifstream                                                         \
    ifstream;                                                            \
    static_assert(false, "Don't use ifstream, use oi::Scanner instead"); \
    ::std::ifstream
#define scanf(...) static_assert(false, "Don't use scanf(), use oi::Scanner instead")
#define fopen(...) static_assert(false, "Don't use fopen(), use oi::Scanner instead")
#define printf(...) static_assert(false, "Don't use printf(), use oi::checker_verdict or oi::inwer_verdict or oi::bug() instead")
#define puts(...) \
    static_assert(false, "Don't use puts(), use oi::checker_verdict or oi::inwer_verdict instead")
#define exit(...) static_assert(false, "Don't use exit(), use oi::checker_verdict or oi::inwer_verdict instead")
#define _exit(...) \
    static_assert(false, "Don't use _exit(), use oi::checker_verdict or oi::inwer_verdict instead")
#define _Exit(...) \
    static_assert(false, "Don't use _Exit(), use oi::checker_verdict or oi::inwer_verdict instead")
#define rand(...) static_assert(false, "Don't use rand(), use oi::Random")::std::rand
#define mt19337 \
    mt19337;    \
    static_assert(false, "Don't use mt19337, use oi::Random")::std::mt19337
#define mt19337_64 \
    mt19337_64;    \
    static_assert(false, "Don't use mt19337_64, use oi::Random")::std::mt19337_64
#undef assert
#define assert(...) static_assert(false, "Don't use assert, use oi_assert()")
