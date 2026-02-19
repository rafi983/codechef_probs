#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int first = -1;
    int last = -1;

    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') {
            if (first == -1) {
                first = i;
            }
            last = i;
        }
    }

    if (first == -1) {
        cout << 0 << endl;
    } else {
        int count = 0;
        for (int i = first; i <= last; ++i) {
            if (s[i] == '0') {
                count++;
            }
        }
        cout << count << endl;
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

