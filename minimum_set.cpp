#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll calc_min_xor(ll L_prime, ll R_prime, int b) {
    ll min_val = 0;
    bool strict_lower = true;
    bool strict_upper = true;

    for (int k = b - 1; k >= 0; --k) {
        int l_bit = (L_prime >> k) & 1;
        int r_bit = (R_prime >> k) & 1;

        bool can_x_0 = !strict_lower || (l_bit == 0);
        bool can_x_1 = true;

        bool can_y_0 = true;
        bool can_y_1 = !strict_upper || (r_bit == 1);

        if (can_x_0 && can_y_0) {
            if (strict_upper && r_bit == 1) strict_upper = false;
        } else if (can_x_1 && can_y_1) {
            if (strict_lower && l_bit == 0) strict_lower = false;
        } else {
            min_val |= (1LL << k);
        }
    }
    return min_val;
}

ll solve(ll L, ll R) {
    if (L >= R) return 0;

    ll diff = L ^ R;
    int b = 63 - __builtin_clzll(diff);

    ll size = R - L + 1;
    if (size == (1LL << (b + 1)) && (L & ((1LL << (b + 1)) - 1)) == 0) {
        return (ll)(b + 1) * (1LL << b);
    }

    ll M = L | ((1LL << b) - 1);

    ll edge_cost = (1LL << b) + calc_min_xor(L & ((1LL << b) - 1), R & ((1LL << b) - 1), b);

    return edge_cost + solve(L, M) + solve(M + 1, R);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    if (cin >> T) {
        while(T--) {
            ll N;
            cin >> N;
            cout << solve(1, N) << "\n";
        }
    }
    return 0;
}

