#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        long long x, m;
        cin >> x >> m;

        if (m == 0) {
            cout << 0 << "\n";
            continue;
        }

        if (x == 1) {
            cout << m << "\n";
            continue;
        }

        long long inv = 1;
        long long ops = 0;

        while (inv < x && ops < m) {
            inv *= 2;
            ops++;
        }

        if (inv < x) {
            cout << 0 << "\n";
        } else {
            cout << m - ops << "\n";
        }
    }

    return 0;
}
