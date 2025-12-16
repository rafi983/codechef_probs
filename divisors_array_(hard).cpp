#include <iostream>
#include <vector>

using namespace std;

const int MAX = 10000005;
const int MOD = 1000000007;

int spf[MAX];
int count_M[MAX]; // Stores exponent of p in M!
int inv_count_plus_1[MAX]; // Stores modular inverse of (count_M[p] + 1)

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

void sieve() {
    for (int i = 1; i < MAX; i++) spf[i] = i;
    for (int i = 2; i * i < MAX; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j < MAX; j += i)
                if (spf[j] == j)
                    spf[j] = i;
        }
    }
}

void solve() {
    int N, M;
    if (!(cin >> N >> M)) return;

    vector<int> A(N);
    for(int i=0; i<N; ++i) cin >> A[i];

    long long base_ans = 1;

    // Calculate exponents for M!
    for (int i = 2; i <= M; ++i) {
        if (spf[i] == i) { // i is prime
            long long cnt = 0;
            long long p = i;
            long long curr = p;
            while (curr <= M) {
                cnt += M / curr;
                if (M / p < curr) break;
                curr *= p;
            }
            count_M[i] = cnt;
            long long term = (cnt + 1) % MOD;
            base_ans = (base_ans * term) % MOD;
            inv_count_plus_1[i] = modInverse(term);
        }
    }

    for (int i = 0; i < N; ++i) {
        long long current_ans = base_ans;
        int temp = A[i];
        while (temp > 1) {
            int p = spf[temp];
            int exponent_in_A = 0;
            while (temp % p == 0) {
                exponent_in_A++;
                temp /= p;
            }

            long long num = 0;
            long long invDen = 1;

            if (p <= M) {
                num = (count_M[p] + exponent_in_A + 1) % MOD;
                invDen = inv_count_plus_1[p];
            } else {
                num = (exponent_in_A + 1) % MOD;
            }

            current_ans = (current_ans * num) % MOD;
            current_ans = (current_ans * invDen) % MOD;
        }
        cout << current_ans << (i == N - 1 ? "" : " ");
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sieve();
    solve();
    return 0;
}

