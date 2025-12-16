#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void solve() {
    int N;
    if (!(cin >> N)) return;
    string S, T_str;
    cin >> S >> T_str;

    int countS = 0;
    for (char c : S) {
        if (c == '1') countS++;
    }

    int countT = 0;
    for (char c : T_str) {
        if (c == '1') countT++;
    }

    if ((countS % 2) == (countT % 2)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    if (cin >> T) {
        while (T--) {
            solve();
        }
    }
    return 0;
}

