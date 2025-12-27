#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void solve() {
    long long N;
    if (!(cin >> N)) return;

    vector<long long> factors;
    for (long long i = 1; i * i <= N; ++i) {
        if (N % i == 0) {
            factors.push_back(i);
            if (i * i != N) {
                factors.push_back(N / i);
            }
        }
    }
    sort(factors.begin(), factors.end());

    for (int K = 1; ; ++K) {
        long long mX = (K + 1) / 2 - 1;
        long long mY = K / 2;

        long long min_prod = (mX + 1) * (mY + 1);
        if (min_prod > N) {
            cout << -1 << "\n";
            return;
        }

        // Check max product
        if (mX + mY < 60) { // 2^60 > 10^18 > 10^9
            long long max_prod = (1LL << mX) * (1LL << mY);
            if (max_prod < N) continue;
        }

        long long LA = mX + 1;
        long long RA = (mX >= 30) ? N : (1LL << mX);

        long long RB_limit = (mY >= 30) ? N : (1LL << mY);

        // A >= N / 2^mY  => A >= ceil(N / RB_limit)
        long long min_A_from_B = (N + RB_limit - 1) / RB_limit;

        // A <= N / (mY + 1)
        long long max_A_from_B = N / (mY + 1);

        long long Low = max(LA, min_A_from_B);
        long long High = min(RA, max_A_from_B);

        if (Low <= High) {
            auto it = lower_bound(factors.begin(), factors.end(), Low);
            if (it != factors.end() && *it <= High) {
                cout << K << "\n";
                return;
            }
        }
    }
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

