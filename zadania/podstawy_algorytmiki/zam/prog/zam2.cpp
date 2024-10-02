#define debug if(1)
#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<int(n);++i)
#define FOR(i,a,b) for (int i=(a); i<(b); ++i)
#define FORD(i,a,b) for (int i=((int)(a))-1; i>=(b); --i)
#define FWD(i,a,b) for (int i=(a); i<(b); ++i)
#define BCK(i,a,b) for (int i=(a); i>(b); --i)
#define SIZE(c) ((int)((c).size()))
#define ALL(v) (v).begin(), (v).end()
#define VAR(v) #v << " " << v << " "
#define pb push_back
#define mp make_pair
#define st first
#define nd second
template<typename T>
ostream& dbg_print(ostream& out, const T& dbg_t){
    out << "[";
    for (auto i : dbg_t) out << i << ", ";
    out << "]";
    return out;
}
template<typename T> ostream& operator<<(ostream& out, const set<T>& dbg_t) {
    return dbg_print(out, dbg_t);
}
template<typename T> ostream& operator<<(ostream& out, const vector<T>& dbg_t) {
    return dbg_print(out, dbg_t);
}
template<typename S, typename T> ostream& operator<<(ostream& out, const pair<S, T>& rhs) {
    out << "(" << rhs.st << "," << rhs.nd << ")";
    return out;
}
template<typename T> void max_e(T& aaa, const T& bbb) { aaa = max(aaa, bbb); }
template<typename T> void min_e(T& aaa, const T& bbb) { aaa = min(aaa, bbb); }
typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;

char encode_digit(int digit) {
    if (digit < 10) return char('0' + digit);
    else if (digit == 10) return 'A';
    else if (digit == 11) return 'B';
    else if (digit == 12) return 'C';
    else if (digit == 13) return 'D';
    else if (digit == 14) return 'E';
    else if (digit == 15) return 'F';
    else assert(false);
}

int decode_digit(char digit) {
    if (digit >= 'A') return 10 + int(digit - 'A');
    else return digit - '0';
}

string encode(int num10, int base) {
    string result;
    while (num10) {
        result = encode_digit(num10 % base) + result;
        num10 /= base;
    }
    if (result == "") result = "0";
    return result;
}

int decode(string num_b, int base) {
    int result = 0;
    for (auto i : num_b) {
        result *= base;
        result += decode_digit(i);
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(0);
    int z; cin >> z;
    while (z--) {
        string cmd;
        cin >> cmd;
        if (cmd == "code" ) {
            int num10; cin >> num10;
            int dest_base; cin >> dest_base;
            cout << encode(num10, dest_base) << endl;
        } else {
            string num_b; cin >> num_b;
            int src_base; cin >> src_base;
            cout << decode(num_b, src_base) << endl;
        }
    }
    return 0;
}
