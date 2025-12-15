#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool isPalindrome(const string& s, int start, int end) {
    while (start < end) {
        if (s[start] != s[end]) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    if (isPalindrome(s, 0, n - 1)) {
        cout << 0 << endl;
        return;
    }

    bool prefixP = isPalindrome(s, 0, n - 2);
    bool suffixP = isPalindrome(s, 1, n - 1);

    if (prefixP && suffixP) {
        cout << -1 << endl;
    } else {
        cout << 1 << endl;
    }
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

