#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int N, K, D;
    if (!(cin >> N >> K >> D)) return;
    vector<int> T(N);
    for (int i = 0; i < N; ++i) {
        cin >> T[i];
    }

    vector<int> avail(N, 1); // All available from day 1
    long long total_plucks = 0;

    for (int day = 1; day <= D; ++day) {
        vector<int> available_indices;
        available_indices.reserve(N);
        for (int i = 0; i < N; ++i) {
            if (avail[i] <= day) {
                available_indices.push_back(i);
            }
        }

        int count = (int)available_indices.size();
        int to_pluck = max(0, count - K);

        if (to_pluck > 0) {
            // Sort available flowers by regrowth time T[i] ascending
            sort(available_indices.begin(), available_indices.end(), [&](int a, int b) {
                return T[a] < T[b];
            });

            for (int i = 0; i < to_pluck; ++i) {
                int idx = available_indices[i];
                total_plucks++;
                avail[idx] = day + T[idx];
            }
        }
    }

    cout << total_plucks << "\n";
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
