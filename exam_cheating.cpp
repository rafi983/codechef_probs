#include <bits/stdc++.h>
using namespace std;

int countDivisors(long long n) {
    int count = 0;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            count++;
            if (i != n / i) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        long long a, b;
        cin >> a >> b;

        if (a == b) {
            cout << -1 << "\n";
        } else {
            long long diff = abs(a - b);
            cout << countDivisors(diff) << "\n";
        }
    }

    return 0;
}
