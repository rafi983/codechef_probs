#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

long long power(long long base, long long exp) {
    long long res = 1;
    base %= 998244353;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % 998244353;
        base = (base * base) % 998244353;
        exp /= 2;
    }
    return res;
}

long long modInverse(long long n) {
    return power(n, 998244353 - 2);
}

void solve() {
    int N;
    if (!(cin >> N)) return;
    vector<int> A(N);
    vector<int> cnt(N + 5, 0);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        if (A[i] < N + 5) {
            cnt[A[i]]++;
        }
    }

    int z = -1;
    for (int i = 0; i < N + 5; ++i) {
        if (cnt[i] == 0) {
            z = i;
            break;
        }
    }

    int z2 = -1;
    for (int i = z + 1; i < N + 5; ++i) {
        if (cnt[i] == 0) {
            z2 = i;
            break;
        }
    }

    long long MOD = 998244353;
    vector<long long> W(z + 1);
    vector<long long> Pre(z + 1);
    vector<long long> InvW(z + 1);
    vector<long long> SumInv(z + 1);


    long long current_pre = 1;
    long long current_sum_inv = 0;

    for (int i = 0; i < z; ++i) {
        W[i] = (power(2, cnt[i]) - 1 + MOD) % MOD;
        current_pre = (current_pre * W[i]) % MOD;
        Pre[i] = current_pre;
        InvW[i] = modInverse(W[i]);
        current_sum_inv = (current_sum_inv + InvW[i]) % MOD;
        SumInv[i] = current_sum_inv;
    }

    // Precompute Suf
    // Suf[y] = N - count(<= y)
    vector<int> count_le(N + 5, 0);
    int current_count = 0;
    for (int i = 0; i < N + 5; ++i) {
        current_count += cnt[i];
        count_le[i] = current_count;
    }

    auto get_suf = [&](int y) {
        if (y >= N + 4) return 0;
        return N - count_le[y];
    };

    long long ans = 0;

    // Part 1: x < z, y <= z
    for (int y = 1; y <= z; ++y) {
        long long term = y;
        long long suf_pow = power(2, get_suf(y));
        term = (term * suf_pow) % MOD;

        long long pre_val = (y - 1 < 0) ? 1 : Pre[y - 1]; // Pre[y-1] is product 0..y-1


        long long p_val = (y == 0) ? 1 : Pre[y - 1]; // Actually y starts at 1.
        // But wait, if y=1, Pre[0] is valid.
        // If z=0, loop doesn't run. Correct.

        long long s_val = (y == 0) ? 0 : SumInv[y - 1];

        term = (term * p_val) % MOD;
        term = (term * s_val) % MOD;

        ans = (ans + term) % MOD;
    }

    // Part 2: x = z, z < y <= z2
    // We need Pre[z-1].
    long long pre_z_minus_1 = (z == 0) ? 1 : Pre[z - 1];

    long long current_prod = 1;
    for (int y = z + 1; y <= z2; ++y) {
        long long term = y;
        long long suf_pow = power(2, get_suf(y));
        term = (term * suf_pow) % MOD;
        term = (term * pre_z_minus_1) % MOD;
        term = (term * current_prod) % MOD;

        ans = (ans + term) % MOD;

        long long w_y = (power(2, cnt[y]) - 1 + MOD) % MOD;
        current_prod = (current_prod * w_y) % MOD;
    }

    // Subtract 1 for empty set
    ans = (ans - 1 + MOD) % MOD;
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}

