#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long power(long long base, long long exp, long long mod) {
    long long res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

long long modInverse(long long n, long long mod) {
    return power(n, mod - 2, mod);
}

long long fact[40];
long long invFact[40];

void precomputeFactorials(int n, long long mod) {
    fact[0] = 1;
    invFact[0] = 1;
    for (int i = 1; i <= n; ++i) {
        fact[i] = (fact[i - 1] * i) % mod;
        invFact[i] = modInverse(fact[i], mod);
    }
}

long long dp[36][36][36];
long long next_dp[36][36][36];
long long tmp[36][36][36];

void solve() {
    int N;
    long long P;
    if (!(cin >> N >> P)) return;

    precomputeFactorials(N, P);

    for (int i = 0; i <= N; ++i)
        for (int j = 0; j <= N; ++j)
            for (int k = 0; k <= N; ++k)
                dp[i][j][k] = 0;

    int OFFSET = N;
    dp[0][0][OFFSET] = 1;

    for (int step = 1; step <= N; ++step) {
        for(int i=0; i<=N; ++i) for(int j=0; j<=N; ++j) for(int k=0; k<=N; ++k) tmp[i][j][k] = 0;

        for (int uA = 0; uA <= N; ++uA) {
            for (int uB = 0; uB <= N; ++uB) {
                for (int m = 0; m <= N; ++m) {
                    if (dp[uA][uB][m] == 0) continue;
                    long long val = dp[uA][uB][m];
                    for (int a = 0; uA + a <= N; ++a) {
                        int nA = uA + a;
                        long long term = (val * invFact[a]) % P;
                        tmp[nA][uB][m] = (tmp[nA][uB][m] + term) % P;
                    }
                }
            }
        }

        for(int i=0; i<=N; ++i) for(int j=0; j<=N; ++j) for(int k=0; k<=N; ++k) next_dp[i][j][k] = 0;

        for (int uA = 0; uA <= N; ++uA) {
            for (int uB = 0; uB <= N; ++uB) {
                for (int m = 0; m <= N; ++m) {
                    if (tmp[uA][uB][m] == 0) continue;
                    long long val = tmp[uA][uB][m];
                    // Try all 'b' >= 0
                    for (int b = 0; uB + b <= N; ++b) {
                        int nB = uB + b;
                        long long term = (val * invFact[b]) % P;
                        next_dp[uA][nB][m] = (next_dp[uA][nB][m] + term) % P;
                    }
                }
            }
        }

        for(int i=0; i<=N; ++i) for(int j=0; j<=N; ++j) for(int k=0; k<=N; ++k) dp[i][j][k] = 0;

        for (int uA = 0; uA <= N; ++uA) {
            for (int uB = 0; uB <= N; ++uB) {
                for (int m = 0; m <= N; ++m) {
                    if (next_dp[uA][uB][m] == 0) continue;
                    // Current diff
                    int diff = uA - uB;
                    // Current min encoded is m - OFFSET
                    int current_min_val = m - OFFSET;
                    int new_min_val = min(current_min_val, diff);
                    // Encode
                    int new_m = new_min_val + OFFSET;

                    // Clamp index
                    if (new_m < 0) new_m = 0;

                    dp[uA][uB][new_m] = (dp[uA][uB][new_m] + next_dp[uA][uB][m]) % P;
                }
            }
        }
    }

    long long sum_min = 0;
    for (int m = 0; m <= N; ++m) {
        if (dp[N][N][m] == 0) continue;
        int min_val = m - OFFSET;
        long long term = (min_val * dp[N][N][m]) % P;
        sum_min = (sum_min + term) % P;
    }

    // Formula: -N * sum_min * (N!)^2
    long long factN = fact[N];
    long long combinations = (factN * factN) % P;
    long long ans = (sum_min * combinations) % P;
    ans = (ans * (-N)) % P;

    if (ans < 0) ans += P;

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    if (cin >> T) {
        while(T--) {
            solve();
        }
    }
    return 0;
}
