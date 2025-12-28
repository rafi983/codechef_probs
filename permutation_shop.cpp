#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <map>

using namespace std;

long long MOD = 998244353;

long long fact[200005];
long long invFact[200005];

long long power(long long base, long long exp) {
    long long res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

long long modInverse(long long n) {
    return power(n, MOD - 2);
}

void precompute() {
    fact[0] = 1;
    invFact[0] = 1;
    for (int i = 1; i <= 200000; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
        invFact[i] = modInverse(fact[i]);
    }
}

long long nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
}

int N;
vector<int> P;
vector<int> fixed_pos; // 1-based positions of 1..N, 0 if not fixed
int M; // count of -1
vector<int> minus_one_indices; // 1-based indices of -1s

long long count_ways(const vector<int>& perm) {
    // perm contains a subset of 1..N
    // Check consistency with fixed positions
    vector<int> fixed_in_perm;
    vector<int> missing_in_perm;

    for (int x : perm) {
        if (fixed_pos[x] != 0) {
            fixed_in_perm.push_back(x);
        } else {
            missing_in_perm.push_back(x);
        }
    }

    // Check relative order of fixed elements
    for (size_t i = 0; i + 1 < fixed_in_perm.size(); ++i) {
        if (fixed_pos[fixed_in_perm[i]] > fixed_pos[fixed_in_perm[i+1]]) {
            return 0;
        }
    }


    // Groups of missing elements
    vector<int> group_sizes;
    int current_group_size = 0;

    for (int x : perm) {
        if (fixed_pos[x] != 0) {
            group_sizes.push_back(current_group_size);
            current_group_size = 0;
        } else {
            current_group_size++;
        }
    }
    group_sizes.push_back(current_group_size);

    // Regions of -1s
    // Defined by positions of fixed_in_perm
    vector<int> region_sizes;

    if (fixed_in_perm.empty()) {
        region_sizes.push_back(M);
    } else {
        // Before first fixed
        int p1 = fixed_pos[fixed_in_perm[0]];
        // Count -1s before p1
        int cnt = lower_bound(minus_one_indices.begin(), minus_one_indices.end(), p1) - minus_one_indices.begin();
        region_sizes.push_back(cnt);

        for (size_t i = 0; i + 1 < fixed_in_perm.size(); ++i) {
            int pa = fixed_pos[fixed_in_perm[i]];
            int pb = fixed_pos[fixed_in_perm[i+1]];
            // Count -1s between pa and pb
            int cnt_a = lower_bound(minus_one_indices.begin(), minus_one_indices.end(), pa) - minus_one_indices.begin();
            int cnt_b = lower_bound(minus_one_indices.begin(), minus_one_indices.end(), pb) - minus_one_indices.begin();
            region_sizes.push_back(cnt_b - cnt_a);
        }

        // After last fixed
        int last_p = fixed_pos[fixed_in_perm.back()];
        int cnt_last = lower_bound(minus_one_indices.begin(), minus_one_indices.end(), last_p) - minus_one_indices.begin();
        region_sizes.push_back(M - cnt_last);
    }

    long long ways = 1;
    for (size_t i = 0; i < group_sizes.size(); ++i) {
        if (group_sizes[i] > 0) {
            ways = (ways * nCr(region_sizes[i], group_sizes[i])) % MOD;
        }
    }

    int missing_count = missing_in_perm.size();
    ways = (ways * fact[M - missing_count]) % MOD;

    return ways;
}

void solve() {
    cin >> N;
    P.resize(N);
    fixed_pos.assign(N + 1, 0);
    minus_one_indices.clear();
    M = 0;
    for (int i = 0; i < N; ++i) {
        cin >> P[i];
        if (P[i] != -1) {
            fixed_pos[P[i]] = i + 1;
        } else {
            minus_one_indices.push_back(i + 1);
            M++;
        }
    }

    long long total_ans = 0;

    // k=2
    if (N >= 3) {
        vector<int> p = {1, 2, 3};
        sort(p.begin(), p.end());
        do {
            // Check if 3 is between 1 and 2
            int i1, i2, i3;
            for(int i=0; i<3; ++i) {
                if(p[i]==1) i1=i;
                else if(p[i]==2) i2=i;
                else if(p[i]==3) i3=i;
            }
            if ((i3 > i1 && i3 < i2) || (i3 > i2 && i3 < i1)) {
                total_ans = (total_ans + count_ways(p)) % MOD;
            }
        } while (next_permutation(p.begin(), p.end()));
    }

    // k=3
    int limit = min(N, 6);
    if (N >= 6) {
        vector<int> p(limit);
        iota(p.begin(), p.end(), 1);
        do {
            bool ok = true;
            // Check conditions
            int pos[7];
            for(int i=0; i<limit; ++i) pos[p[i]] = i;

            auto get_S = [&](int Y) {
                int s = 0;
                int posY = pos[Y];
                if (pos[1] < posY) s += 1;
                if (pos[2] < posY) s += 2;
                if (pos[3] < posY) s += 3;
                return s;
            };

            if (limit >= 4) {
                if (get_S(4) != 3) ok = false;
            }
            if (ok && limit >= 5) {
                int s = get_S(5);
                if (s < 2 || s > 4) ok = false;
            }
            if (ok && limit >= 6) {
                int s = get_S(6);
                if (s < 1 || s > 5) ok = false;
            }

            if (ok) {
                total_ans = (total_ans + count_ways(p)) % MOD;
            }

        } while (next_permutation(p.begin(), p.end()));
    }

    cout << total_ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precompute();
    int T;
    cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}
