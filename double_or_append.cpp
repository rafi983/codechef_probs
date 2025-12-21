#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int M;
    if (!(cin >> M)) return;

    long long L = 1;
    long long I = 0;
    long long K = 0;

    for (int i = 0; i < M; ++i) {
        int type;
        cin >> type;
        if (type == 1) {
            I = I + L;
            K = K + L;
            L = L + 1;
        } else {
            I = 2 * I + K;
            K = 4 * K;
            L = 2 * L;
        }
        cout << I << (i == M - 1 ? "" : " ");
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

