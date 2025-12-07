#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        if (n % 2 == 1) {
            cout << -1 << "\n";
        } else {
            int big = 1000000000;
            cout << 1;
            for (int i = 1; i < n - 1; i++) {
                if (i % 2 == 1) {
                    cout << " " << -big;
                } else {
                    cout << " " << big;
                }
            }
            cout << " 0\n";
        }
    }

    return 0;
}

