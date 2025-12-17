#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct State {
    int min_val;
    int max_val;
};

void solve() {
    int N;
    if (!(cin >> N)) return;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // dp[i][j] stores the min and max possible value of the survivor of range [i, j]
    // indices are 0-based
    vector<vector<State>> dp(N, vector<State>(N));

    for (int i = 0; i < N; ++i) {
        dp[i][i] = {A[i], A[i]};
    }

    for (int len = 2; len <= N; ++len) {
        for (int i = 0; i <= N - len; ++i) {
            int j = i + len - 1;
            int current_min = 2000; // Larger than any possible value
            int current_max = -1;   // Smaller than any possible value

            for (int k = i; k < j; ++k) {
                State left = dp[i][k];
                State right = dp[k+1][j];


                int val1_max = max(0, left.max_val - right.min_val);
                int val1_min = max(0, left.min_val - right.max_val);


                int val2_max = max(0, right.max_val - left.min_val);
                int val2_min = max(0, right.min_val - left.max_val);

                current_max = max({current_max, val1_max, val2_max});
                current_min = min({current_min, val1_min, val2_min});
            }
            dp[i][j] = {current_min, current_max};
        }
    }

    cout << dp[0][N-1].max_val << endl;
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

