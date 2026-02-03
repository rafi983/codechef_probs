#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>

using namespace std;

void solve() {
    int N;
    double K_req;

    if (!(cin >> N >> K_req)) return;

    int num_buckets = sqrt(N);
    if (num_buckets < 1) num_buckets = 1;

    vector<vector<int>> buckets(num_buckets);

    for (int v = 1; v <= N; ++v) {
        int b_idx = num_buckets - 1 - ((v - 1) % num_buckets);
        buckets[b_idx].push_back(v);
    }

    bool first = true;
    for (int i = 0; i < num_buckets; ++i) {
        for (int val : buckets[i]) {
            if (!first) cout << " ";
            cout << val;
            first = false;
        }
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
