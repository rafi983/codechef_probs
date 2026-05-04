#include <bits/stdc++.h>
using namespace std;

static long long tri(long long x) {
    return x * (x + 1) / 2;
}

static string repeat_char(char c, long long cnt) {
    if (cnt <= 0) return "";
    return string((size_t)cnt, c);
}

static string build_small(long long n, long long x) {
    if (x == 0) return "";

    long long lo = 0, hi = n, best = 0;
    while (lo <= hi) {
        long long mid = (lo + hi) / 2;
        if (tri(mid) <= x) {
            best = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    long long t = best;
    long long rem = x - tri(t);
    string s;

    if (rem == 0) {
        s += repeat_char('0', t - 1);
        s += repeat_char('1', t);
    } else if (rem < t) {
        s += repeat_char('0', t - 1);
        s += repeat_char('1', rem + 1);
        s += '0';
        s += repeat_char('1', t - rem - 1);
    } else {
        if (t == 1) s = "1001";
        else if (t == 2) s = "10011";
        else if (t == 3) s = "0011100";
        else {
            s += repeat_char('0', t - 2);
            s += "110";
            s += repeat_char('1', t - 2);
            s += '0';
        }
    }
    return s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        long long n, k;
        cin >> n >> k;

        long long total = (n / 2 + 1) * ((n + 1) / 2);

        if (k < 0 || k > total || (n == 3 && k == 2)) {
            cout << -1 << '\n';
            continue;
        }

        bool flip = false;
        long long x = k;
        if (2 * k > total) {
            x = total - k;
            flip = true;
        }

        string core = build_small(n, x);
        if ((long long)core.size() > n) {
            cout << -1 << '\n';
            continue;
        }

        string ans = repeat_char('0', n - (long long)core.size()) + core;

        if (flip) {
            for (char &c : ans) c = (c == '0' ? '1' : '0');
        }

        reverse(ans.begin(), ans.end());
        cout << ans << '\n';
    }

    return 0;
}
