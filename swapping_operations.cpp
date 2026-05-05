#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        int fixed_ones = 0, q = 0;
        for (char c : s) {
            if (c == '1') ++fixed_ones;
            else if (c == '?') ++q;
        }
        int fixed_zeros = n - fixed_ones - q;

        int mn = n;
        {
            string reduced;
            reduced.reserve(n - q);
            for (char c : s) if (c != '?') reduced.push_back(c);

            int m = (int)reduced.size();
            int k = fixed_ones;
            if (k == 0) {
                mn = 0;
            } else {
                int zeros = 0;
                for (int i = 0; i < k; ++i) zeros += (reduced[i] == '0');
                mn = min(mn, zeros);
                for (int i = k; i < m; ++i) {
                    zeros += (reduced[i] == '0');
                    zeros -= (reduced[i - k] == '0');
                    mn = min(mn, zeros);
                }
            }
        }

        int mx = 0;

        for (int k = fixed_ones; k <= fixed_ones + q; ++k) {
            auto feasible = [&](int x) {
                if (k == 0) return x == 0;

                string cur = s;
                vector<int> st;
                st.reserve(n + 1);
                st.push_back(-1);

                int zeros_in_window = 0;
                int used_zeros = fixed_zeros;

                for (int i = 0; i < n; ++i) {
                    if (cur[i] == '?') st.push_back(i);
                    if (cur[i] == '0') ++zeros_in_window;

                    if (i >= k && cur[i - k] == '0') --zeros_in_window;
                    if (i < k - 1) continue;

                    while (zeros_in_window < x) {
                        int pos = st.back();
                        if (pos <= i - k) break;

                        st.pop_back();
                        cur[pos] = '0';
                        ++zeros_in_window;
                        ++used_zeros;
                    }

                    if (zeros_in_window < x) return false;
                }

                return used_zeros <= n - k;
            };

            int lo = 0, hi = k;
            while (lo < hi) {
                int mid = (lo + hi + 1) / 2;
                if (feasible(mid)) lo = mid;
                else hi = mid - 1;
            }

            mx = max(mx, lo);
        }

        cout << mn << ' ' << mx << '\n';
    }

    return 0;
}
