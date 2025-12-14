#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void solve() {
    long long K;
    if (!(cin >> K)) return;

    long long N = K - 1;

    if (N == 0) {
        cout << "0\n";
        return;
    }

    string ans = "";
    while (N > 0) {
        int rem = N % 5;
        ans += (char)('0' + rem * 2);
        N /= 5;
    }

    reverse(ans.begin(), ans.end());
    cout << ans << "\n";
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

