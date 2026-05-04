// SHIFT & SORT - CodeChef
#include <bits/stdc++.h>
using namespace std;

static bool can_sort_with_one_operation(const vector<long long>& a) {
    int n = (int)a.size();
    if (n <= 1) return true;

    vector<long long> x(n - 1, 0);

    for (int i = 0; i + 1 < n; ++i) {
        if (a[i] > a[i + 1]) {
            if (i > 0 && x[i - 1] > 0) return false;
            long long diff = a[i] - a[i + 1];
            x[i] = (diff + 1) / 2;
        }
    }

    vector<long long> b(n);
    b[0] = a[0] - x[0];
    for (int i = 1; i + 1 < n; ++i) {
        b[i] = a[i] + x[i - 1] - x[i];
    }
    b[n - 1] = a[n - 1] + x[n - 2];

    for (int i = 0; i + 1 < n; ++i) {
        if (b[i] > b[i + 1]) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];

        cout << (can_sort_with_one_operation(a) ? "Yes" : "No") << '\n';
    }
    return 0;
}
