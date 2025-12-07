#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        long long x;
        cin >> x;

        long long n = (long long)((-1 + sqrt(1 + 8.0 * x)) / 2);

        while (n * (n + 1) / 2 < x) n++;

        long long station_pos = n * (n + 1) / 2;

        if (station_pos == x) {
            cout << n << "\n";
        } else {
            long long prev_station = (n - 1) * n / 2;
            long long walk_from_prev = x - prev_station;
            long long walk_from_curr = station_pos - x;

            long long option1 = n - 1 + walk_from_prev;
            long long option2 = n + walk_from_curr;
            long long option3 = x;

            cout << min({option1, option2, option3}) << "\n";
        }
    }

    return 0;
}

