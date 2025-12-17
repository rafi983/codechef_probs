#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int N;
    if (!(cin >> N)) return;
    vector<long long> A(N);
    long long max_val = 0;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        max_val = max(max_val, A[i]);
    }


    if (max_val > 2LL * N) {
        sort(A.begin(), A.end());
        long long ans = 0;
        int current_count = 0;
        for (int i = 0; i < N; ++i) {
            current_count++;
            if (i == N - 1 || A[i] != A[i+1]) {
                ans = max(ans, A[i] + current_count);
                current_count = 0;
            }
        }
        cout << ans << endl;
    } else {
        // Use sieve-like approach
        // max_val is relatively small (<= 2*N)
        int M = (int)max_val;
        vector<int> freq(M + 1, 0);
        for (long long x : A) {
            freq[(int)x]++;
        }

        long long ans = max_val + 1;

        for (int g = 1; g <= M; ++g) {
            int count = 0;
            for (int k = g; k <= M; k += g) {
                count += freq[k];
            }
            if (count > 0) {
                ans = max(ans, (long long)g + count);
            }
        }
        cout << ans << endl;
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

