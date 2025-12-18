#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef long long ll;

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

typedef long long ll;

ll get_cost(int r, int c, int N, int M) {
    ll A = max((ll)r, (ll)N / r);
    ll B = max((ll)c, (ll)M / c);
    return A * B;
}

struct State {
    ll d;
    int r, c;
    bool operator>(const State& other) const {
        return d > other.d;
    }
};

pair<ll, ll> explore(int start_r, int start_c, int target_r, int target_c,
                     int N, int M,
                     const vector<int>& dN, const vector<int>& dM) {

    bool start_in_N = binary_search(dN.begin(), dN.end(), start_r);
    bool start_in_M = binary_search(dM.begin(), dM.end(), start_c);

    if (!start_in_N || !start_in_M) {
        return {-1, 0};
    }

    map<pair<int, int>, ll> dist;
    priority_queue<State, vector<State>, greater<State>> pq;

    ll start_cost = get_cost(start_r, start_c, N, M);
    dist[{start_r, start_c}] = start_cost;
    pq.push({start_cost, start_r, start_c});

    ll min_sea_dist = -1;
    ll min_target_dist = -1;

    while (!pq.empty()) {
        State top = pq.top();
        pq.pop();
        ll d = top.d;
        int r = top.r;
        int c = top.c;

        if (dist.count({r, c}) && d > dist[{r, c}]) continue;

        if (r == target_r && c == target_c) {
            if (min_target_dist == -1 || d < min_target_dist) {
                min_target_dist = d;
            }
        }

        if (min_target_dist != -1 && d >= min_target_dist && min_sea_dist != -1 && d >= min_sea_dist) {
             return {min_target_dist, min_sea_dist};
        }

        bool is_border = false;
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr <= 0 || nc <= 0) continue;

            bool nr_in_N = binary_search(dN.begin(), dN.end(), nr);
            bool nc_in_M = binary_search(dM.begin(), dM.end(), nc);

            if (nr_in_N && nc_in_M) {
                ll new_cost = d + get_cost(nr, nc, N, M);
                if (!dist.count({nr, nc}) || new_cost < dist[{nr, nc}]) {
                    dist[{nr, nc}] = new_cost;
                    pq.push({new_cost, nr, nc});
                }
            } else {
                is_border = true;
            }
        }

        if (is_border) {
            if (min_sea_dist == -1 || d < min_sea_dist) {
                min_sea_dist = d;
            }
        }
    }

    return {min_target_dist, min_sea_dist};
}

void solve() {
    int N, M, P, Q;
    if (!(cin >> N >> M >> P >> Q)) return;

    vector<int> dN, dM;
    for (int i = 1; i * i <= N; ++i) {
        if (N % i == 0) {
            dN.push_back(i);
            if (i * i != N) dN.push_back(N / i);
        }
    }
    for (int i = 1; i * i <= M; ++i) {
        if (M % i == 0) {
            dM.push_back(i);
            if (i * i != M) dM.push_back(M / i);
        }
    }
    sort(dN.begin(), dN.end());
    sort(dM.begin(), dM.end());

    pair<ll, ll> resS = explore(1, 1, P, Q, N, M, dN, dM);
    pair<ll, ll> resT = explore(P, Q, 1, 1, N, M, dN, dM);

    ll ans = -1;

    ll sea_path = -1;
    if (resS.second != -1 && resT.second != -1) {
        sea_path = resS.second + resT.second;
    }

    ll direct_path = resS.first;

    if (sea_path != -1) {
        ans = sea_path;
    }
    if (direct_path != -1) {
        if (ans == -1 || direct_path < ans) {
            ans = direct_path;
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

