#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

void solve() {
    int N, X;
    cin >> N >> X;

    vector<int> P(N + 1, 0);

    for (int i = 1; i <= N; ++i) {
        if (P[i] != 0) continue;

        // Check if i is a submask of X
        if ((i | X) == X) {
            int t = i ^ X;
            // We can pair i with t if t is within range [1, N]
            if (t >= 1 && t <= N) {
                P[i] = t;
                P[t] = i;
            }
        }
    }

    // Fill the remaining positions
    for (int i = 1; i <= N; ++i) {
        if (P[i] == 0) {
            P[i] = i;
        }
    }

    for (int i = 1; i <= N; ++i) {
        cout << P[i] << (i == N ? "" : " ");
    }
    cout << "\n";
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

