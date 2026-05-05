#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        if (n == 2) {
            cout << "01\n";
            continue;
        }

        string s(n, '0');
        s[0] = '1';
        s[n - 1] = '1';
        cout << s << '\n';
    }

    return 0;
}
