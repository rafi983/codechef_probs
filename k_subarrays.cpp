#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

long long gcd(long long a, long long b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

void solve() {
    int n, k;
    if (!(cin >> n >> k)) return;
    vector<int> a(n);
    long long g = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (i == 0) g = a[i];
        else g = gcd(g, a[i]);
    }

    int count = 0;
    long long current_gcd = 0;
    for (int i = 0; i < n; ++i) {
        if (current_gcd == 0) {
            current_gcd = a[i];
        } else {
            current_gcd = gcd(current_gcd, a[i]);
        }

        if (current_gcd == g) {
            count++;
            current_gcd = 0;
        }
    }

    if (count >= k) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
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

