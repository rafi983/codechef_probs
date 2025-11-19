#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        long long N, K;
        string S;
        cin >> N >> K;
        cin >> S;

        char prev = '\0';
        long long diff_in = 0;
        char first_nonI = '\0', last_nonI = '\0';

        for (char c : S) {
            if (c == 'I') continue;
            if (first_nonI == '\0') first_nonI = c;
            if (prev != '\0') {
                if (c != prev) ++diff_in;
            }
            prev = c;
            last_nonI = c;
        }

        long long transitions = 0;
        if (first_nonI == '\0') {
            transitions = 0;
        } else {
            long long diff_boundary = (first_nonI != last_nonI) ? 1 : 0;
            transitions = K * diff_in + (K - 1) * diff_boundary;
        }

        long long total_adj = N * K - 1;
        long long ans = total_adj - transitions;
        cout << ans << '\n';
    }
    return 0;
}

