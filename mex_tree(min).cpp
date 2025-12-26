#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int N;
    if (!(cin >> N)) return;

    vector<int> degree(N + 1, 0);
    for (int i = 0; i < N - 1; ++i) {
        int u, v;
        cin >> u >> v;
        degree[u]++;
        degree[v]++;
    }

    int max_degree = 0;
    for (int i = 1; i <= N; ++i) {
        max_degree = max(max_degree, degree[i]);
    }

    if (max_degree <= 2) {
        cout << 2 * N - 1 << endl;
    } else {
        cout << N + 1 << endl;
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
