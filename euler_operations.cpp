#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;

struct Prim {
    ll val;
    ll phi;
};

vector<Prim> primorials;

void precompute() {
    // Generate primorials
    vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}; // Sufficient for 10^9
    ll curr = 1;
    ll curr_phi = 1;

    // Add 1
    primorials.push_back({1, 1});

    for (int p : primes) {
        if (__builtin_mul_overflow(curr, p, &curr)) break;
        curr_phi *= (p - 1);
        primorials.push_back({curr, curr_phi});
        if (curr > 2000000000LL) break; // limit
    }
}

ll solve_rec(ll D, int idx) {
    if (D == 0) return 0;
    if (idx < 0) return 2e18; // Should not happen if 1 is in list

    ll P = primorials[idx].val;
    ll Phi = primorials[idx].phi;

    ll q = D / P;
    ll r = D % P;

    ll cost1 = q * Phi + solve_rec(r, idx - 1);

    ll cost2 = 2e18;
    if (r > 0) {
        cost2 = (q + 1) * Phi + solve_rec(P - r, idx - 1);
    }

    return min(cost1, cost2);
}

void solve() {
    ll M, D;
    if (!(cin >> M >> D)) return;

    int start_idx = 0;
    for (int i = 0; i < primorials.size(); ++i) {
        if (primorials[i].val <= M) {
            start_idx = i;
        } else {
            break;
        }
    }

    cout << solve_rec(D, start_idx) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precompute();
    int T;
    if (cin >> T) {
        while(T--) {
            solve();
        }
    }
    return 0;
}
