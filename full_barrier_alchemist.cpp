#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int N, H, Y1, Y2, L;
        if (!(cin >> N >> H >> Y1 >> Y2 >> L)) return 0;

        int passed = 0;
        bool exhausted = false;

        for (int i = 0; i < N; ++i) {
            int t, X;
            if (!(cin >> t >> X)) return 0;
            if (exhausted) continue;

            bool can_pass = false;
            if (t == 1) {
                can_pass = (X >= H - Y1);
            } else {
                can_pass = (X <= Y2);
            }

            if (can_pass) {
                ++passed;
            } else {
                if (L >= 2) {
                    --L;
                    ++passed;
                } else {
                    exhausted = true;
                }
            }
        }

        cout << passed << '\n';
    }

    return 0;
}

