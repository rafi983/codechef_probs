#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int N, M;
    if (!(cin >> N >> M)) return;
    vector<vector<long long>> A(N, vector<long long>(M));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> A[i][j];
        }
    }

    int max_kept = 0;
    // Patterns: (1, 1), (1, -1), (-1, 1), (-1, -1)
    int cx_opts[] = {1, 1, -1, -1};
    int cy_opts[] = {1, -1, 1, -1};

    for (int k = 0; k < 4; ++k) {
        int cx = cx_opts[k];
        int cy = cy_opts[k];

        vector<long long> diffs;
        diffs.reserve(N * M);
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                // Calculate S = A[i][j] - cx*i - cy*j
                long long val = A[i][j] - (long long)cx * i - (long long)cy * j;
                diffs.push_back(val);
            }
        }
        sort(diffs.begin(), diffs.end());

        int current_run = 0;
        if (!diffs.empty()) {
            current_run = 1;
            for (size_t i = 1; i < diffs.size(); ++i) {
                if (diffs[i] == diffs[i-1]) {
                    current_run++;
                } else {
                    if (current_run > max_kept) max_kept = current_run;
                    current_run = 1;
                }
            }
            if (current_run > max_kept) max_kept = current_run;
        }
    }

    cout << (N * M - max_kept) << endl;
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

