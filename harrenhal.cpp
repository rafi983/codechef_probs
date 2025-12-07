#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(const string& s) {
    int n = s.length();
    for (int i = 0; i < n / 2; i++) {
        if (s[i] != s[n - 1 - i]) {
            return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        string h;
        cin >> h;

        if (h.empty()) {
            cout << 0 << "\n";
        } else if (isPalindrome(h)) {
            cout << 1 << "\n";
        } else {

            cout << 2 << "\n";
        }
    }

    return 0;
}

