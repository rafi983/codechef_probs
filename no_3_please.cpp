#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

bool solve() {
    int N;
    if (!(cin >> N)) return false;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Construct target patterns
    vector<int> T1(N), T2(N);
    if (N > 0) {
        T1[0] = 1;
        T2[0] = 2;
        for (int i = 1; i < N; ++i) {
            if (i == 1) {
                T1[i] = 1;
                T2[i] = 2;
            } else {
                T1[i] = (i % 2 == 0) ? 2 : 1;
                T2[i] = (i % 2 == 0) ? 1 : 2;
            }
        }
    }

    // Precompute suffix matches
    vector<bool> suf1(N + 1, true), suf2(N + 1, true);
    for (int i = N - 1; i >= 0; --i) {
        suf1[i] = suf1[i + 1] && (A[i] == T1[i]);
        suf2[i] = suf2[i + 1] && (A[i] == T2[i]);
    }

    // Precompute alternating lengths
    vector<int> alt(N, 0);
    for (int i = 0; i < N; ++i) {
        if (i == 0) alt[i] = 1;
        else {
            if (A[i] != A[i - 1]) alt[i] = alt[i - 1] + 1;
            else alt[i] = 1;
        }
    }

    for (int k = 1; k <= N; ++k) {
        // Check T1
        bool match1 = false;
        if (suf1[k]) {
            if (k == 1) {
                if (A[0] == 1) match1 = true;
            } else if (k == 2) {
                if (A[0] == 1 && A[1] == 1) match1 = true;
            } else {
                if (A[k - 1] == 1 && A[k - 2] == 1 && A[k - 3] == 2 && alt[k - 3] >= k - 2) match1 = true;
            }
        }
        if (match1) {
            cout << "Yes" << endl;
            return true;
        }

        // Check T2
        bool match2 = false;
        if (suf2[k]) {
            if (k == 1) {
                if (A[0] == 2) match2 = true;
            } else if (k == 2) {
                if (A[0] == 2 && A[1] == 2) match2 = true;
            } else {
                if (A[k - 1] == 2 && A[k - 2] == 2 && A[k - 3] == 1 && alt[k - 3] >= k - 2) match2 = true;
            }
        }
        if (match2) {
            cout << "Yes" << endl;
            return true;
        }
    }

    cout << "No" << endl;
    return true;
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

