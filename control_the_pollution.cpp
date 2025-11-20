#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        long long N, X, Y;
        cin >> N >> X >> Y;

        long long hundreds = N / 100;
        long long rem = N % 100;

        long long cost_per_100 = min(X, 25LL * Y);
        long long cost = hundreds * cost_per_100;

        long long cars_needed_for_rem = (rem + 3) / 4;
        long long rem_cost = min(X, cars_needed_for_rem * Y);
        cost += rem_cost;

        cout << cost << "\n";
    }
    return 0;
}

