#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;

        int one_runs = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1' && (i == 0 || s[i - 1] == '0')) ++one_runs;
        }

        string ans(n, '0');
        int pos = (s[n - 1] == '1') ? (n - 1) : (n - 2);

        for (int k = 0; k < one_runs; ++k) {
            ans[pos] = '1';
            pos -= 2;
        }

        cout << ans << '\n';
    }

    return 0;
}
