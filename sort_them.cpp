#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int INF = 1e9;

void solve() {
    int N;
    if (!(cin >> N)) return;
    string S, P;
    cin >> S >> P;

    vector<int> pos(26);
    for (int i = 0; i < 26; ++i) {
        pos[P[i] - 'a'] = i;
    }

    auto get_mirror = [&](char c) {
        int p = pos[c - 'a'];
        int mirror_p = 25 - p;
        return P[mirror_p];
    };



    int prev_dp0 = 0;
    int prev_dp1 = 1;

    for (int i = 1; i < N; ++i) {
        char prev_orig = S[i-1];
        char prev_flip = get_mirror(S[i-1]);
        char curr_orig = S[i];
        char curr_flip = get_mirror(S[i]);

        int curr_dp0 = INF;
        int curr_dp1 = INF;

        // Calculate curr_dp0 (keep current)
        if (prev_orig <= curr_orig) {
            curr_dp0 = min(curr_dp0, prev_dp0);
        }
        if (prev_flip <= curr_orig) {
            curr_dp0 = min(curr_dp0, prev_dp1);
        }

        // Calculate curr_dp1 (flip current)
        if (prev_orig <= curr_flip) {
            curr_dp1 = min(curr_dp1, prev_dp0 + 1);
        }
        if (prev_flip <= curr_flip) {
            curr_dp1 = min(curr_dp1, prev_dp1 + 1);
        }

        prev_dp0 = curr_dp0;
        prev_dp1 = curr_dp1;
    }

    int ans = min(prev_dp0, prev_dp1);
    if (ans >= INF) {
        cout << -1 << endl;
    } else {
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

