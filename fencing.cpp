#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        long long n, m, k;
        cin >> n >> m >> k;

        set<pair<long long, long long>> plants;

        for (int i = 0; i < k; i++) {
            long long r, c;
            cin >> r >> c;
            plants.insert({r, c});
        }

        long long adjacentPairs = 0;

        for (auto& p : plants) {
            long long r = p.first;
            long long c = p.second;

            if (plants.count({r - 1, c})) adjacentPairs++;
            if (plants.count({r + 1, c})) adjacentPairs++;
            if (plants.count({r, c - 1})) adjacentPairs++;
            if (plants.count({r, c + 1})) adjacentPairs++;
        }

        adjacentPairs /= 2;

        long long fences = 4 * k - 2 * adjacentPairs;

        cout << fences << "\n";
    }

    return 0;
}
