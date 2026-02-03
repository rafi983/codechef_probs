#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

bool hasOddDigit(long long n) {
    string s = to_string(n);
    for (char c : s) {
        if ((c - '0') % 2 != 0) return true;
    }
    return false;
}

bool allDigitsIdentical(long long n) {
    string s = to_string(n);
    for (size_t i = 1; i < s.length(); ++i) {
        if (s[i] != s[0]) return false;
    }
    return true;
}

int solve_case(long long n) {
    if (n % 2 != 0) return 0;

    if (hasOddDigit(n)) return 1;

    string s = to_string(n);
    vector<int> digits;
    for (char c : s) digits.push_back(c - '0');

    for (int d : digits) {
        long long next_n = n - d;
        if (hasOddDigit(next_n)) return 2;
    }


    if (!allDigitsIdentical(n)) {
        return 3;
    }

    int d = digits[0];
    long long next_n = n - d;

    if (next_n == 0) return -1; // 8 -> 0 -> stuck

    int sub_res = solve_case(next_n);
    if (sub_res == -1) return -1;
    return 1 + sub_res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    if (cin >> T) {
        while (T--) {
            long long N;
            cin >> N;
            cout << solve_case(N) << "\n";
        }
    }
    return 0;
}
