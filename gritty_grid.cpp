#include <iostream>

using namespace std;

void solve() {
    long long N, M, X, Y;
    if (!(cin >> N >> M >> X >> Y)) return;

    long long D = N + M - 2;

    if ((X + Y) % 2 != 0) {
        cout << "YES" << endl;
    } else {
        if ((D + Y) % 2 == 0) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}

