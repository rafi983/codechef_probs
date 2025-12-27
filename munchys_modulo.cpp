#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

void solve() {
    int N;
    if (!(cin >> N)) return;
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    sort(A.rbegin(), A.rend());

    if (A[1] + A[2] > A[0]) {
        cout << A[0] << "\n";
        return;
    }

    long long ans = A[1];

    for (int j = 1; j < N; ++j) {
        for (int k = j + 1; k < N; ++k) {
            long long sum = A[j] + A[k];

            long long val = A[0] % sum;
            if (val > ans) {
                ans = val;
            }
        }
    }
    cout << ans << "\n";
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

