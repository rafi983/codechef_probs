#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

long long floor_div(long long a, long long k) {
    long long val = a / k;
    if (a < 0 && a % k != 0) val--;
    return val;
}

long long ceil_div(long long a, long long k) {
    long long val = a / k;
    if (a > 0 && a % k != 0) val++;
    return val;
}

void solve() {
    int N;
    long long K;
    if (!(cin >> N >> K)) return;

    long long s_min = 0;
    long long s_max = 0;

    for (int i = 0; i < N; ++i) {
        long long a;
        cin >> a;
        s_min += floor_div(a, K);
        s_max += ceil_div(a, K);
    }

    if (s_min <= 0 && s_max >= 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
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

