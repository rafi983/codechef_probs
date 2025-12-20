#include <iostream>
#include <vector>
#include <string>
#include <numeric>

using namespace std;

void solve() {
    int N;
    if (!(cin >> N)) return;
    string S, T_str;
    cin >> S >> T_str;

    int p = -1;
    for (int i = 0; i < N; ++i) {
        if (S[i] == '1') {
            p = i;
            break;
        }
    }

    if (p == -1) {
        // S has no 1s
        if (S == T_str) {
            cout << "0\n\n";
        } else {
            cout << "-1\n";
        }
        return;
    }

    // Check prefix S[0...p] == T_str[0...p]
    for (int i = 0; i <= p; ++i) {
        if (S[i] != T_str[i]) {
            cout << "-1\n";
            return;
        }
    }

    vector<int> ops;
    // Phase 1: Propagate 1s from p to N-1
    for (int i = p; i < N - 1; ++i) {
        // We are at index i (which is '1'). We want to ensure S[i+1] is '1'.
        if (S[i+1] == '0') {
            // Flip S[i+1]
            S[i+1] = '1';
            ops.push_back(i + 1); // 1-based index
        }
    }

    // Phase 2: Fix S to T from right to left
    for (int j = N - 1; j > p; --j) {
        if (S[j] != T_str[j]) {
            // Flip S[j] using S[j-1]
            S[j] = (S[j] == '1' ? '0' : '1');
            ops.push_back(j); // 1-based index of the pivot (j-1 in 0-based is j in 1-based)
        }
    }

    cout << ops.size() << "\n";
    for (int i = 0; i < ops.size(); ++i) {
        cout << ops[i] << (i == ops.size() - 1 ? "" : " ");
    }
    cout << "\n";
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

