#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

using namespace std;

void solve() {
    int N, Q;
    if (!(cin >> N >> Q)) return;
    string s1, s2;
    cin >> s1 >> s2;

    vector<int> x, y;
    for (int i = 0; i < N; ++i) {
        if (s1[i] == '1') x.push_back(i + 1);
    }
    for (int i = 0; i < N; ++i) {
        if (s2[i] == '1') y.push_back(i + 1);
    }

    int cnt1 = x.size();
    int cnt2 = y.size();

    // Precompute prefix sums
    vector<long long> Px(cnt1 + 1, 0);
    for (int i = 0; i < cnt1; ++i) Px[i + 1] = Px[i] + x[i];

    vector<long long> Py(cnt2 + 1, 0);
    for (int i = 0; i < cnt2; ++i) Py[i + 1] = Py[i] + y[i];

    int L = max(1, N - cnt2 + 1);
    int R = min(N, cnt1);

    if (L > R) {
        cout << -1 << endl;
        return;
    }

    long long min_ops = -1;

    for (int k = L; k <= R; ++k) {
        // Cost for row 1: move first k ones to 1..k
        long long cost1 = Px[k] - (long long)k * (k + 1) / 2;

        // Cost for row 2: move last N-k+1 ones to k..N
        int m = N - k + 1;
        long long sum_y = Py[cnt2] - Py[cnt2 - m];

        long long sum_target = (long long)(k + N) * m / 2;

        long long cost2 = sum_target - sum_y;

        long long total = cost1 + cost2;
        if (min_ops == -1 || total < min_ops) {
            min_ops = total;
        }
    }

    cout << min_ops << endl;
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
