#include <bits/stdc++.h>
using namespace std;

static inline unsigned long long countMultiplesOf3UpTo(unsigned long long n) {
    return n / 3ULL;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        unsigned long long L, R;
        cin >> L >> R;
        unsigned long long ans = countMultiplesOf3UpTo(R) - countMultiplesOf3UpTo(L - 1ULL);
        cout << ans << '\n';
    }
    return 0;
}

