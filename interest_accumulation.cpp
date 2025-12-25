#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const long long INF = 1e18;
const int MOD = 998244353;

struct Matrix {
    long long m[2][2];

    Matrix() {
        m[0][0] = m[0][1] = m[1][0] = m[1][1] = -INF;
    }
};

Matrix multiply(const Matrix& A, const Matrix& B) {
    Matrix C;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                if (A.m[i][k] > -INF && B.m[k][j] > -INF) {
                    C.m[i][j] = max(C.m[i][j], A.m[i][k] + B.m[k][j]);
                }
            }
        }
    }
    return C;
}

struct PrefData {
    long long X; // a - b
    long long a, b;
};

struct SufData {
    long long Y; // d - c
    long long c, d;
};

int N;
vector<long long> A;
vector<Matrix> M;

long long solve(int l, int r) {
    if (l == r) {
        return max(0LL, A[l]) % MOD;
    }

    int mid = l + (r - l) / 2;
    long long ans = (solve(l, mid) + solve(mid + 1, r)) % MOD;



    vector<SufData> sufs;
    sufs.reserve(mid - l + 1);

    Matrix curr;
    curr = M[mid];
    sufs.push_back({curr.m[1][0] - curr.m[0][0], curr.m[0][0], curr.m[1][0]});

    for (int i = mid - 1; i >= l; --i) {
        curr = multiply(curr, M[i]); // Note order: M[mid]...M[i+1] * M[i]
        sufs.push_back({curr.m[1][0] - curr.m[0][0], curr.m[0][0], curr.m[1][0]});
    }

    vector<PrefData> prefs;
    prefs.reserve(r - mid);

    curr = M[mid + 1];
    prefs.push_back({curr.m[0][0] - curr.m[0][1], curr.m[0][0], curr.m[0][1]});

    for (int i = mid + 2; i <= r; ++i) {
        curr = multiply(M[i], curr); // Note order: M[i] * M[i-1]...M[mid+1]
        prefs.push_back({curr.m[0][0] - curr.m[0][1], curr.m[0][0], curr.m[0][1]});
    }

    // Sort prefs by X
    sort(prefs.begin(), prefs.end(), [](const PrefData& p1, const PrefData& p2) {
        return p1.X < p2.X;
    });

    int n_prefs = prefs.size();
    vector<long long> sum_a(n_prefs + 1, 0);
    vector<long long> sum_b(n_prefs + 1, 0);

    for (int i = 0; i < n_prefs; ++i) {
        sum_a[i+1] = (sum_a[i] + (prefs[i].a % MOD)) % MOD;
        sum_b[i+1] = (sum_b[i] + (prefs[i].b % MOD)) % MOD;
    }

    for (const auto& s : sufs) {
        long long Y = s.Y;


        auto it = upper_bound(prefs.begin(), prefs.end(), Y, [](long long val, const PrefData& p) {
            return val < p.X;
        });

        int idx = distance(prefs.begin(), it);



        long long count_greater = n_prefs - idx;
        long long count_less = idx;

        long long term1 = 0;
        if (count_greater > 0) {
            long long sum_a_part = (sum_a[n_prefs] - sum_a[idx] + MOD) % MOD;
            long long c_part = (s.c % MOD * (count_greater % MOD)) % MOD;
            term1 = (sum_a_part + c_part) % MOD;
        }

        long long term2 = 0;
        if (count_less > 0) {
            long long sum_b_part = sum_b[idx];
            long long d_part = (s.d % MOD * (count_less % MOD)) % MOD;
            term2 = (sum_b_part + d_part) % MOD;
        }

        ans = (ans + term1 + term2) % MOD;
    }

    return ans;
}

void solve_test_case() {
    if (!(cin >> N)) return;
    A.resize(N);
    M.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        long long k = i + 1;
        M[i].m[0][0] = max(0LL, A[i]);
        M[i].m[0][1] = k;
        M[i].m[1][0] = A[i] - k;
        M[i].m[1][1] = 0;
    }

    cout << solve(0, N - 1) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    if (cin >> T) {
        while (T--) {
            solve_test_case();
        }
    }
    return 0;
}
