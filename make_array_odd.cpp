#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int N;
        unsigned int X;
        if (!(cin >> N >> X)) return 0;
        int evens = 0;
        for (int i = 0; i < N; ++i) {
            unsigned int a;
            cin >> a;
            if ((a & 1u) == 0u) ++evens;
        }
        if ((X & 1u) == 1u) {
            int ops = (evens + 1) / 2;
            cout << ops << '\n';
        } else {
            if (evens == N) {
                cout << -1 << '\n';
            } else {
                cout << evens << '\n';
            }
        }
    }
    return 0;
}

