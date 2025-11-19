#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int stored = 0;
        bool possible = true;
        int first_fail_day = -1;

        for(int i = 0; i < n; i++) {
            stored += a[i];

            if(stored < k) {
                possible = false;
                first_fail_day = i + 1;
                break;
            }

            stored -= k;
        }

        if(possible) {
            cout << "YES" << endl;
        } else {
            cout << "NO " << first_fail_day << endl;
        }
    }

    return 0;
}
