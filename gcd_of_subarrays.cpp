#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        long long n, k;
        cin >> n >> k;

        long long total_subarrays = n * (n + 1) / 2;

        if (k < total_subarrays) {
            cout << -1 << "\n";
        } else {
            long long first = k - total_subarrays + 1;
            cout << first;
            for (int i = 1; i < n; i++) {
                cout << " " << 1;
            }
            cout << "\n";
        }
    }

    return 0;
}

