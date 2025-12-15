#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    long long current_sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        current_sum += a[i];
    }

    int i = 1;
    while (i < n - 1) {
        if (a[i] == 3) {
            int j = i;
            while (j < n - 1 && a[j] == 3) {
                j++;
            }
            int k = j - i;
            int l_val = a[i - 1];
            int r_val = a[j]; // a[j] is the element after the block

            int rem = k;

            if (l_val == 1 || r_val == 1) {
                if (l_val + r_val == 4) {
                    rem = 0;
                } else {
                    rem = 1;
                }
            } else {
                // Neither is 1
                if (l_val == 2 && r_val == 2 && k == 1) {
                    rem = 0;
                } else {
                    rem = k;
                }
            }

            current_sum -= 2LL * (k - rem);
            i = j;
        } else {
            i++;
        }
    }

    cout << current_sum << endl;
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

