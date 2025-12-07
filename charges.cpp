#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        string s;
        cin >> s;

        int samePairs = 0;
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                samePairs++;
            }
        }

        for (int i = 0; i < k; i++) {
            int q;
            cin >> q;
            q--;

            if (q > 0) {
                if (s[q] == s[q - 1]) samePairs--;
                else samePairs++;
            }
            if (q < n - 1) {
                if (s[q] == s[q + 1]) samePairs--;
                else samePairs++;
            }

            s[q] = (s[q] == '0') ? '1' : '0';

            cout << (n - 1) + samePairs << "\n";
        }
    }

    return 0;
}
