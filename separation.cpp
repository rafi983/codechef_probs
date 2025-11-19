#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int N; long long X;
        cin >> N >> X;
        long long cL = 0, cE = 0, cG = 0;
        for (int i = 0; i < N; ++i) {
            long long a; cin >> a;
            if (a < X) ++cL;
            else if (a == X) ++cE;
            else ++cG;
        }
        bool ok = (cL == 0 || cG == 0) || (cE > 0);
        cout << (ok ? "Yes" : "No") << "\n";
    }
    return 0;
}

