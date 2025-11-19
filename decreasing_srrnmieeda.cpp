#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long l;
        long long r;
        cin >> l >> r;
        if (r >= 2 * l) {
            cout << -1 << '\n';
        } else {
            cout << r << '\n';
        }
    }
    return 0;
}
