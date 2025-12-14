#include <iostream>
#include <cmath>

using namespace std;

long long countDivisors(long long n) {
    long long count = 0;
    for (long long i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            if (i * i == n) {
                count++;
            } else {
                count += 2;
            }
        }
    }
    return count;
}

void solve() {
    long long n;
    cin >> n;
    long long divisors = countDivisors(n);
    if (n % 2 == 0) {
        cout << 2 * divisors - 3 << endl;
    } else {
        cout << 2 * divisors - 2 << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

