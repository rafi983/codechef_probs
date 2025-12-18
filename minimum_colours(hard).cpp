#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

void solve() {
    int N;
    if (!(cin >> N)) return;
    vector<int> A(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
    }


    vector<int> min_group_v(N + 1, INF);
    int min_group_0 = INF;
    int min_all = INF;



    int dp_val = 0; // DP[0]
    min_all = 0;

    if (A[1] == 0) {
        min_group_0 = 0;
    } else {
        min_group_v[A[1]] = 0;
    }

    int current_dp = 0;
    for (int i = 1; i <= N; ++i) {
        if (A[i] == 0) {
            // Compatible with any previous segment
            current_dp = 1 + min_all;
        } else {
            // Compatible with previous segments ending with 0 or A[i]
            current_dp = 1 + min(min_group_0, min_group_v[A[i]]);
        }

        if (i < N) {
            // Update for next iteration
            min_all = min(min_all, current_dp);
            if (A[i+1] == 0) {
                min_group_0 = min(min_group_0, current_dp);
            } else {
                min_group_v[A[i+1]] = min(min_group_v[A[i+1]], current_dp);
            }
        }
    }
    cout << current_dp << "\n";
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

