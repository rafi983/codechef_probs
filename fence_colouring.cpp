#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int N;
    if (!(cin >> N)) return;

    vector<int> counts(N + 1, 0);
    int max_freq = 0;

    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        if (a <= N) {
             counts[a]++;
             max_freq = max(max_freq, counts[a]);
        }
    }

    int count1 = counts[1];

    int cost1 = N - count1;
    int cost2 = 1 + N - max_freq;

    cout << min(cost1, cost2) << endl;
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

