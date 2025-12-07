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

        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        sort(a.begin(), a.end(), greater<long long>());

        multiset<long long> boxes;

        for (int i = 0; i < n; i++) {
            auto it = boxes.lower_bound(a[i]);

            if (it != boxes.end()) {
                long long oldXor = *it;
                boxes.erase(it);
                boxes.insert(oldXor ^ a[i]);
            } else {
                boxes.insert(a[i]);
            }
        }

        cout << boxes.size() << "\n";
    }

    return 0;
}
