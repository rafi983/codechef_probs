#include <iostream>

using namespace std;

long long power(long long base, long long exp) {
    long long res = 1;
    base %= 998244353;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % 998244353;
        base = (base * base) % 998244353;
        exp /= 2;
    }
    return res;
}

void solve() {
    int N;
    cin >> N;
    if (N % 2 != 0) {
        // Odd
        cout << power(2, N - 1) << endl;
    } else {
        // Even
        long long ans = (3 * power(2, N - 2)) % 998244353;
        cout << ans << endl;
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
