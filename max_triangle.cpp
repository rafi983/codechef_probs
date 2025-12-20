#include <iostream>

using namespace std;

void solve() {
    long long N;
    if (!(cin >> N)) return;



    if (N >= 4) {
        cout << 3 * N - 3 << "\n";
    } else {
        cout << -1 << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    if (cin >> T) {
        while (T--) {
            solve();
        }
    }
    return 0;
}

