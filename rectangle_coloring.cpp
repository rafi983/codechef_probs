#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Config {
    int m[4];
};

vector<Config> configs_by_cost[13];

int countSetBits(int n) {
    int count = 0;
    while (n > 0) {
        n &= (n - 1);
        count++;
    }
    return count;
}

void precompute() {
    vector<pair<int, int>> pA, pB;
    for (int i = 1; i <= 7; ++i) {
        for (int j = i; j <= 7; ++j) {
            pA.push_back({i, j});
        }
    }
    pB = pA;

    for (const auto &pa : pA) {
        for (const auto &pb : pB) {
            int cost = countSetBits(pa.first) + countSetBits(pa.second) +
                       countSetBits(pb.first) + countSetBits(pb.second);
            configs_by_cost[cost].push_back({pa.first, pa.second, pb.first, pb.second});
        }
    }
}

bool check(const Config& cfg, long long S[], long long P[]) {

    for (int mask = 1; mask <= 7; ++mask) {
        long long supply = 0;
        if (mask & 1) supply += P[0];
        if (mask & 2) supply += P[1];
        if (mask & 4) supply += P[2];

        long long demand = 0;
        if (cfg.m[0] & mask) demand += S[0];
        if (cfg.m[1] & mask) demand += S[1];
        if (cfg.m[2] & mask) demand += S[2];
        if (cfg.m[3] & mask) demand += S[3];

        if (supply > demand) return false;
    }
    return true;
}

void solve() {
    long long L, W, R, G, B;
    if (!(cin >> L >> W >> R >> G >> B)) return;
    long long S[4] = {L, L, W, W};
    long long P[3] = {R, G, B};

    for (int cost = 4; cost <= 12; ++cost) {
        for (const auto &cfg : configs_by_cost[cost]) {
            if (check(cfg, S, P)) {
                cout << cost << "\n";
                return;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precompute();
    int T;
    if (cin >> T) {
        while(T--) {
            solve();
        }
    }
    return 0;
}
