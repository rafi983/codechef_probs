#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        set<int> s;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            s.insert(x);
        }

        if (s.size() == 1) {
            cout << 0 << "\n";
        } else {
            auto it = s.rbegin();
            it++;
            cout << *it << "\n";
        }
    }

    return 0;
}
