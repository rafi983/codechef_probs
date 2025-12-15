#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector<int> b(n);
    for (int i = 0; i < n; ++i) cin >> b[i];

    int max_a_idx = -1;
    int second_max_a_idx = -1;

    for (int i = 0; i < n; ++i) {
        if (max_a_idx == -1 || a[i] > a[max_a_idx]) {
            max_a_idx = i;
        }
    }

    for (int i = 0; i < n; ++i) {
        if (i == max_a_idx) continue;
        if (second_max_a_idx == -1 || a[i] > a[second_max_a_idx]) {
            second_max_a_idx = i;
        }
    }

    int v_max_idx = max(a[max_a_idx], b[max_a_idx]);
    int v_second_max_idx = max(a[second_max_a_idx], b[second_max_a_idx]);

    if (v_max_idx > v_second_max_idx) {
        cout << "Yes" << endl;
        return;
    }

    for (int i = 0; i < n; ++i) {
        if (i == max_a_idx) continue;
        int v_i = max(a[i], b[i]);
        if (v_i > v_max_idx) {
            cout << "Yes" << endl;
            return;
        }
    }

    cout << "No" << endl;
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

