#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

void solve() {
    int N;
    long long X;
    if (!(cin >> N >> X)) return;

    vector<long long> A(N);
    map<long long, vector<int>> positions;
    int max_orig_freq = 0;

    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        positions[A[i]].push_back(i);
    }

    for (auto const& [val, pos] : positions) {
        if ((int)pos.size() > max_orig_freq) {
            max_orig_freq = pos.size();
        }
    }

    if (X == 1) {
        cout << max_orig_freq << "\n";
        return;
    }

    int ans = max_orig_freq;

    for (auto const& [u, pos_u] : positions) {
        long long v = u * X;

        auto it = positions.find(v);
        if (it == positions.end()) {
            if ((int)pos_u.size() > ans) {
                ans = pos_u.size();
            }
            continue;
        }

        const vector<int>& pos_v = it->second;

        int current_base = pos_v.size();
        int max_gain = 0;
        int current_gain = 0;

        int i = 0, j = 0;
        while (i < pos_u.size() || j < pos_v.size()) {
            int val;
            if (i < pos_u.size() && (j >= pos_v.size() || pos_u[i] < pos_v[j])) {
                val = 1;
                i++;
            } else {
                val = -1;
                j++;
            }

            current_gain += val;
            if (current_gain < 0) current_gain = 0;
            if (current_gain > max_gain) max_gain = current_gain;
        }

        if (current_base + max_gain > ans) {
            ans = current_base + max_gain;
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

