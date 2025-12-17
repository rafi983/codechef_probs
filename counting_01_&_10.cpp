#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    long long N;
    if (!(cin >> N)) return;

    long long ans = 0;
    long long limit = N / 2;

    for (long long i = 0; i <= limit; ++i) {
        ans += (i * (N - i) + 1);
    }

    cout << ans << "\n";
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

