#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;

    int countA_s = 0;
    int firstA_s = -1;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'a') {
            countA_s++;
            if (firstA_s == -1) firstA_s = i;
        }
    }

    int countA_t = 0;
    int firstA_t = -1;
    for (int i = 0; i < m; ++i) {
        if (t[i] == 'a') {
            countA_t++;
            if (firstA_t == -1) firstA_t = i;
        }
    }

    if (countA_s != countA_t) {
        cout << "No" << endl;
        return;
    }

    if (countA_s == 0) {
        if (s == t) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
        return;
    }

    if (firstA_s == firstA_t) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
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

