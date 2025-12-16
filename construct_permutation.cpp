#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int N;
    if (!(cin >> N)) return;

    if (N % 2 == 0) {
        cout << -1 << endl;
    } else {
        for (int i = 1; i <= N; ++i) {
            if (i % 2 != 0) {
                cout << (N - (i - 1)) << (i == N ? "" : " ");
            } else {
                cout << i << (i == N ? "" : " ");
            }
        }
        cout << endl;
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

