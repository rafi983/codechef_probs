#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void solve() {
    int N;
    if (!(cin >> N)) return;
    string S;
    cin >> S;


    vector<vector<bool>> dp(N + 1, vector<bool>(3, false));

    // Base case: 0 lights processed, covered up to 0.
    // i=0, coverage=0 => offset = 0 - 0 = 0.
    dp[0][0 + 1] = true;

    for (int i = 0; i < N; ++i) {
        char status = S[i];

        for (int off = -1; off <= 1; ++off) {
            if (!dp[i][off + 1]) continue;

            // Option 1: Light is broken
            if (status == '0') {

                int new_off = off - 1;
                if (new_off >= -1) {
                    dp[i + 1][new_off + 1] = true;
                }
            }
            // Option 2: Light is working
            else {

                {
                    int new_off = 0;
                    dp[i + 1][new_off + 1] = true;
                }


                if (off >= 0) {
                    // New coverage end becomes i+2.
                    // New offset = (i+2) - (i+1) = 1.
                    int new_off = 1;
                    dp[i + 1][new_off + 1] = true;
                }
            }
        }
    }

    if (dp[N][0 + 1] || dp[N][1 + 1]) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
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

