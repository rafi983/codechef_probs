#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void solve() {
    int X, Y, Z;
    if (!(cin >> X >> Y >> Z)) return;

    // Maximize pairs for each character type
    int kA = X / 2;
    int kB = Y / 2;
    int kC = Z / 2;

    // Remaining singletons
    int rA = X % 2;
    int rB = Y % 2;
    int rC = Z % 2;

    int deltaBC = (rB + rC > 0) ? 1 : 0;
    int deltaAC = (rA + rC > 0) ? 1 : 0;
    int deltaAB = (rA + rB > 0) ? 1 : 0;

    int scoreBC = 2 * kB + 2 * kC + deltaBC;
    int scoreAC = 2 * kA + 2 * kC + deltaAC;
    int scoreAB = 2 * kA + 2 * kB + deltaAB;

    cout << min({scoreBC, scoreAC, scoreAB}) << "\n";
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

