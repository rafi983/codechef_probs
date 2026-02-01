#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

void solve() {
    int N;
    int A, B;
    if (!(cin >> N >> A >> B)) return;

    vector<int> T(N);
    for (int i = 0; i < N; ++i) {
        cin >> T[i];
    }

    int dp0 = 0;
    int dp1 = INF;

    for (int i = 0; i < N; ++i) {
        int next_dp0 = INF;
        int next_dp1 = INF;

        if (T[i] >= A) {
            next_dp0 = min(dp0, dp1);
        }

        if (T[i] <= B) {
            next_dp1 = min(dp0 + 1, dp1);
        }

        dp0 = next_dp0;
        dp1 = next_dp1;
    }

    cout << min(dp0, dp1) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}
