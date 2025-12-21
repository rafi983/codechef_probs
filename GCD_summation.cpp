#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

void solve() {
    int N;
    long long K;
    if (!(cin >> N >> K)) return;

    if (K < N - 1) {
        cout << -1 << endl;
        return;
    }

    long long X = K - (N - 2);


    cout << X << " " << 2 * X;
    for (int i = 2; i < N; ++i) {
        cout << " " << (2 * X + (i - 1));
    }
    cout << endl;
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

