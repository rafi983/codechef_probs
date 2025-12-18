#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

void solve() {
    long long N, K;
    if (!(cin >> N >> K)) return;

    if (N >= 2 * K + 1) {
        cout << "1 " << N << endl;
        return;
    }


    for (long long b = N; b >= K + 2; --b) {
        long long limit = b - K;
        // We only need to check a few numbers. If b is divisible by 1..50, it must be huge.
        long long check_limit = min(limit, 100LL);

        for (long long a = 2; a <= check_limit; ++a) {
            if (b % a != 0) {
                cout << a << " " << b << endl;
                return;
            }
        }
    }

    cout << "-1 -1" << endl;
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

