#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int N;
    cin >> N;
    string A;
    cin >> A;

    // Check if N is a power of 2
    if ((N & (N - 1)) == 0) {
        cout << -1 << endl;
        return;
    }

    int cost = 0;
    for (int i = 1; i <= N; ++i) {
        int target = -1; // -1 means unforced, take A[i-1]

        // Check if i is a power of 2
        if ((i & (i - 1)) == 0) {
            target = 1;
        } else {

            int v = (~i) & (i + 1);
            if (i + v > N) {
                target = 0;
            }
        }

        if (target != -1) {
            int current = A[i - 1] - '0';
            if (current != target) {
                cost++;
            }
        }
    }
    cout << cost << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}

