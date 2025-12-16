#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int N;
    long long L, R;
    if (!(cin >> N >> L >> R)) return;
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());
    bool duplicate = false;
    for (int i = 0; i < N - 1; ++i) {
        if (A[i] == A[i+1]) {
            duplicate = true;
            break;
        }
    }

    long long prod;
    if (duplicate) {
        prod = 0;
    } else if (N > 60) {
        prod = R + 1;
    } else {
        prod = 1;
        bool overflow = false;
        for (int i = 0; i < N; ++i) {
            for (int j = i + 1; j < N; ++j) {
                long long val = A[i] ^ A[j];



                prod *= val;
                if (prod > R) {
                    overflow = true;
                    break;
                }
            }
            if (overflow) break;
        }
        if (overflow) prod = R + 1;
    }

    if (prod >= L && prod <= R) {
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

