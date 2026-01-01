#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

long long MOD = 1e9 + 7;

struct Query {
    int l, r, k, id;
};

int N, Q;
vector<long long> A;
vector<Query> queries;
vector<long long> answers;
vector<long long> coeffs;
int BLOCK_SIZE;

bool compareQueries(const Query& a, const Query& b) {
    int block_a = a.l / BLOCK_SIZE;
    int block_b = b.l / BLOCK_SIZE;
    if (block_a != block_b)
        return block_a < block_b;
    return (block_a % 2 == 0) ? (a.r < b.r) : (a.r > b.r);
}

void add(int val, int& current_deg) {
    if (current_deg + 1 >= coeffs.size()) coeffs.resize(current_deg + 2, 0);

    for (int i = current_deg + 1; i >= 1; --i) {
        coeffs[i] = (coeffs[i-1] + (long long)val * coeffs[i]) % MOD;
    }
    coeffs[0] = (coeffs[0] * (long long)val) % MOD;
    current_deg++;
}

void remove(int val, int& current_deg) {
    long long next_val = coeffs[current_deg];

    for (int i = current_deg - 1; i >= 0; --i) {
        long long curr_c = coeffs[i];
        coeffs[i] = next_val;
        next_val = (curr_c - (long long)val * next_val) % MOD;
        if (next_val < 0) next_val += MOD;
    }
    coeffs[current_deg] = 0;
    current_deg--;
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

long long modInverse(long long n) {
    return power(n, MOD - 2);
}

void zaman_solve() {
    int T;
    if (!(cin >> T)) return;
    while (T--) {
        cin >> N >> Q;
        A.resize(N + 1);
        for (int i = 1; i <= N; ++i) {
            cin >> A[i];
        }
        queries.resize(Q);
        for (int i = 0; i < Q; ++i) {
            cin >> queries[i].l >> queries[i].r >> queries[i].k;
            queries[i].id = i;
        }

        if (Q == 0) continue;

        BLOCK_SIZE = max(1, (int)(N / sqrt(Q)));
        sort(queries.begin(), queries.end(), compareQueries);

        answers.resize(Q);
        coeffs.assign(N + 2, 0);
        coeffs[0] = 1;
        int current_deg = 0;
        int currL = 1, currR = 0;

        for (const auto& q : queries) {
            while (currL > q.l) {
                add(A[--currL], current_deg);
            }
            while (currR < q.r) {
                add(A[++currR], current_deg);
            }
            while (currL < q.l) {
                remove(A[currL++], current_deg);
            }
            while (currR > q.r) {
                remove(A[currR--], current_deg);
            }

            int S = current_deg;
            long long K = q.k;
            long long ans = 0;

            long long invS = modInverse(S);
            long long term_invS = 1;
            long long term_PKm = 1;

            for (int m = 0; m <= S; ++m) {
                if (m > K) break;

                long long term = (coeffs[m] * term_PKm) % MOD;
                term = (term * term_invS) % MOD;

                ans = (ans + term) % MOD;

                term_PKm = (term_PKm * ((K - m) % MOD)) % MOD;
                term_invS = (term_invS * invS) % MOD;
            }
            answers[q.id] = ans;
        }

        for (long long ans : answers) {
            cout << ans << "\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    zaman_solve();
    return 0;
}
