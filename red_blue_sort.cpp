#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    int fixed_points = 0;
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        if (p[i] == i + 1) {
            fixed_points++;
        }
    }

    int max_profit = fixed_points;

    vector<bool> visited(n, false);
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            int curr = i;
            int len = 0;
            while (!visited[curr]) {
                visited[curr] = true;
                curr = p[curr] - 1;
                len++;
            }

            if (len < n) {
                int current_fixed = n - len + (len % 2);
                int current_profit = current_fixed - 1;
                if (current_profit > max_profit) {
                    max_profit = current_profit;
                }
            }
        }
    }

    if (n - 2 > max_profit) {
        max_profit = n - 2;
    }

    cout << max_profit << endl;
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

