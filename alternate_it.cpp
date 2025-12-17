#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

void solve() {
    string S;
    cin >> S;
    int n = S.length();

    bool is_alternating = true;
    for (int i = 0; i < n - 1; ++i) {
        if (S[i] == S[i+1]) {
            is_alternating = false;
            break;
        }
    }

    if (is_alternating) {
        cout << 0 << endl;
        return;
    }

    int c0 = 0;
    int c1 = 0;
    for (char c : S) {
        if (c == '0') c0++;
        else c1++;
    }

    int diff = abs(c0 - c1);

    if (diff <= 1) {
        cout << 1 << endl;
    } else if (diff <= 3) {
        cout << 2 << endl;
    } else {
        cout << 3 << endl;
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
