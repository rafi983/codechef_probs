#include <iostream>
#include <vector>

using namespace std;

const int MOD = 998244353;
const int MAXM = 500005;

vector<int> distinct_primes[MAXM];
long long powers[MAXM];

void precompute_primes() {
    for (int i = 2; i < MAXM; ++i) {
        if (distinct_primes[i].empty()) {
            for (int j = i; j < MAXM; j += i) {
                distinct_primes[j].push_back(i);
            }
        }
    }
}

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

void compute_coprime_count(int idx, int current_d, int current_mu, int X, const vector<int>& primes, int& count) {
    if (idx == primes.size()) {
        if (current_mu == 1) count += (X / current_d);
        else count -= (X / current_d);
        return;
    }

    compute_coprime_count(idx + 1, current_d, current_mu, X, primes, count);
    compute_coprime_count(idx + 1, current_d * primes[idx], -current_mu, X, primes, count);
}

void solve() {
    int N, M;
    if (!(cin >> N >> M)) return;

    for (int i = 1; i <= M; ++i) {
        powers[i] = power(i, N);
    }
    powers[0] = 0;

    long long total_ans = 0;

    for (int g = 1; g <= M; ++g) {
        int X = M / g;
        for (int L = 1; L <= X; ++L) {
            int cnt = 0;
            compute_coprime_count(0, 1, 1, X, distinct_primes[L], cnt);
            total_ans = (total_ans + powers[cnt]) % MOD;
        }
    }

    cout << total_ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precompute_primes();
    int T;
    if (cin >> T) {
        while (T--) {
            solve();
        }
    }
    return 0;
}

