#include <bits/stdc++.h>
using namespace std;

static bool can_get_at_least_k(const vector<int>& arr, int k) {
    if (k <= 1) return true;

    vector<int> cur(k, 0);
    set<int> need;
    for (int i = 1; i < k; ++i) need.insert(i);

    for (int x : arr) {
        int lo = 0, hi = k - 1;
        while (lo < hi) {
            int mid = (lo + hi + 1) / 2;
            if (cur[mid] <= x) lo = mid;
            else hi = mid - 1;
        }

        int pos = lo;
        auto it = need.upper_bound(pos);
        if (it == need.begin()) continue;

        --it;
        int idx = *it;
        ++cur[idx];
        if (cur[idx] == idx) need.erase(it);
    }

    return need.empty();
}

static vector<int> build_with_prefix_largest(const vector<int>& sorted_b, int take) {
    int n = (int)sorted_b.size();
    vector<int> out;
    out.reserve(n);

    for (int i = 0; i < take; ++i) out.push_back(sorted_b[n - 1 - i]);
    for (int i = 0; i < n - take; ++i) out.push_back(sorted_b[i]);
    return out;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> b(n);
        for (int i = 0; i < n; ++i) cin >> b[i];

        sort(b.begin(), b.end());

        if (!can_get_at_least_k(b, k)) {
            cout << -1 << '\n';
            continue;
        }

        vector<int> desc = b;
        reverse(desc.begin(), desc.end());
        if (can_get_at_least_k(desc, k + 1)) {
            cout << -1 << '\n';
            continue;
        }

        int lo = 0, hi = n;
        while (lo < hi) {
            int mid = (lo + hi + 1) / 2;
            vector<int> cand = build_with_prefix_largest(b, mid);
            if (can_get_at_least_k(cand, k)) lo = mid;
            else hi = mid - 1;
        }

        vector<int> ans = build_with_prefix_largest(b, lo);
        for (int i = 0; i < n; ++i) {
            cout << ans[i] << (i + 1 == n ? '\n' : ' ');
        }
    }

    return 0;
}
