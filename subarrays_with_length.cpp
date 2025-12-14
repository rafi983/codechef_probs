#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int N;
    if (!(cin >> N)) return;
    vector<int> A(N + 1);
    vector<vector<int>> pos(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
        if (A[i] <= N) {
            pos[A[i]].push_back(i);
        }
    }

    long long total_count = 0;

    for (int k = 1; k <= N; ++k) {
        if (pos[k].empty()) continue;

        int current_start = -1;
        int current_end = -1;

        for (int i : pos[k]) {
            int s = max(1, i - k + 1);
            int e = min(i, N - k + 1);

            if (s > e) continue;

            if (current_start == -1) {
                current_start = s;
                current_end = e;
            } else {
                if (s <= current_end + 1) {
                    current_end = max(current_end, e);
                } else {
                    total_count += (current_end - current_start + 1);
                    current_start = s;
                    current_end = e;
                }
            }
        }
        if (current_start != -1) {
            total_count += (current_end - current_start + 1);
        }
    }

    cout << total_count << endl;
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

