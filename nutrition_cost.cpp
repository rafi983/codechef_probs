#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

void solve() {
    int N, C;
    cin >> N >> C;

    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    vector<int> B(N);
    for (int i = 0; i < N; ++i) {
        cin >> B[i];
    }

    // Map to store minimum cost for each vitamin type
    map<int, int> min_costs;

    for (int i = 0; i < N; ++i) {
        int vitamin = A[i];
        int cost = B[i];
        if (min_costs.find(vitamin) == min_costs.end()) {
            min_costs[vitamin] = cost;
        } else {
            min_costs[vitamin] = min(min_costs[vitamin], cost);
        }
    }

    int total_profit = 0;
    for (auto const& [vitamin, cost] : min_costs) {
        if (C > cost) {
            total_profit += (C - cost);
        }
    }

    cout << total_profit << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}

