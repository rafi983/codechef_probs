#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 1e9 + 7;

int N;
vector<int> A;
vector<int> bit;

void update(int idx, int val) {
    for (; idx <= N; idx += idx & -idx) {
        bit[idx] = (bit[idx] + val) % MOD;
        if (bit[idx] < 0) bit[idx] += MOD;
    }
}

int query(int idx) {
    int sum = 0;
    for (; idx > 0; idx -= idx & -idx) {
        sum = (sum + bit[idx]) % MOD;
    }
    return sum;
}

void solve() {
    if (!(cin >> N)) return;
    A.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    if (bit.size() <= N) bit.assign(N + 1, 0);
    else {
        for(int i=0; i<=N; ++i) bit[i] = 0;
    }

    long long total_ans = 1;
    int current_max = 0;
    int segment_start = 0;

    for (int i = 0; i < N; ++i) {
        current_max = max(current_max, A[i]);
        if (current_max == i + 1) {
            long long segment_ways = 0;
            vector<int> history_vals;

            for (int j = segment_start; j <= i; ++j) {
                int val = A[j];
                int ways = (query(val - 1) + 1) % MOD;
                update(val, ways);
                segment_ways = (segment_ways + ways) % MOD;
                history_vals.push_back(ways);
            }

            total_ans = (total_ans * segment_ways) % MOD;

            for (int j = segment_start; j <= i; ++j) {
                update(A[j], -history_vals[j - segment_start]);
            }

            segment_start = i + 1;
        }
    }

    cout << total_ans << "\n";
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

