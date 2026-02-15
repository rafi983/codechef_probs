#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>

using namespace std;

typedef long long ll;

vector<ll> compute_costs(const vector<ll>& weights) {
    int n = weights.size();
    if (n == 0) return {};
    vector<ll> P_W(n, 0);
    vector<ll> P_WZ(n, 0);

    for (int i = 0; i < n; ++i) {
        P_W[i] = (i > 0 ? P_W[i-1] : 0) + weights[i];
        P_WZ[i] = (i > 0 ? P_WZ[i-1] : 0) + weights[i] * i;
    }

    ll total_W = P_W.back();
    ll total_WZ = P_WZ.back();

    vector<ll> costs(n);
    for (int i = 0; i < n; ++i) {
        ll left_cost = i * P_W[i] - P_WZ[i];
        ll right_cost = (total_WZ - P_WZ[i]) - i * (total_W - P_W[i]);
        costs[i] = left_cost + right_cost;
    }
    return costs;
}

void solve() {
    int N, M;
    if (!(cin >> N >> M)) return;

    int max_dim = N + M + 2;

    vector<ll> W_u(max_dim, 0);
    vector<ll> W_k(max_dim, 0);

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            int val;
            cin >> val;

            int weight = 0;
            if (val == 1) weight = 1;      // Aarsi shoots
            else if (val == 2) weight = -1; // Krypto shoots


            if (weight != 0) {
                int u = i + j;
                int k = i - j + M;
                W_u[u] += weight;
                W_k[k] += weight;
            }
        }
    }

    vector<ll> costs_u = compute_costs(W_u);
    vector<ll> costs_k = compute_costs(W_k);

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            int u = i + j;
            int k = i - j + M;


            ll total = costs_u[u] + costs_k[k];

            cout << abs(total) / 2 << (j == M - 1 ? "" : " ");
        }
        cout << "\n";
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

