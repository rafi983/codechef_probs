#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool check(int n, int k, const vector<int>& a, int x) {
    int changes = 0;
    int i = 0;
    while (i < n) {
        int current_min = a[i] - x;
        int current_max = a[i] + x;
        int j = i + 1;
        while (j < n) {
            int next_min = a[j] - x;
            int next_max = a[j] + x;

            int intersection_min = max(current_min, next_min);
            int intersection_max = min(current_max, next_max);

            if (intersection_min > intersection_max) {
                break;
            }

            current_min = intersection_min;
            current_max = intersection_max;
            j++;
        }
        if (j < n) {
            changes++;
            if (changes > k) return false;
        }
        i = j;
    }
    return true;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int low = 0, high = 1000000000;
    int ans = high;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (check(n, k, a, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    cout << ans << endl;
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

