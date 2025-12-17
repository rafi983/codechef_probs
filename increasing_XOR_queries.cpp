#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

const int MAXN = 200005;
const int INF = 1e9;

int nxt[MAXN][30][2];
int A[MAXN];
int S[MAXN];

void solve() {
    int N, Q;
    if (!(cin >> N >> Q)) return;

    S[0] = 0;
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
        S[i] = S[i-1] ^ A[i];
    }

    // Initialize nxt[N]
    for (int b = 0; b < 30; ++b) {
        nxt[N][b][0] = INF;
        nxt[N][b][1] = INF;
    }

    for (int i = N - 1; i >= 1; --i) {
        for (int b = 0; b < 30; ++b) {
            nxt[i][b][0] = nxt[i+1][b][0];
            nxt[i][b][1] = nxt[i+1][b][1];
        }

        if (A[i+1] > 0) {
            int msb = 31 - __builtin_clz(A[i+1]);
            int val = (S[i] >> msb) & 1;
            nxt[i][msb][val] = i;
        }
    }

    string ans = "";
    ans.reserve(Q);
    for (int q = 0; q < Q; ++q) {
        int L, R;
        cin >> L >> R;
        if (L == R) {
            ans += '1';
            continue;
        }

        bool possible = true;
        for (int b = 0; b < 30; ++b) {
            int pos0 = nxt[L][b][0];
            int pos1 = nxt[L][b][1];
            bool has0 = (pos0 <= R - 1);
            bool has1 = (pos1 <= R - 1);

            if (has0 && has1) {
                possible = false;
                break;
            }
            if (has0) {
                if (((S[L-1] >> b) & 1) != 0) {
                    possible = false;
                    break;
                }
            }
            if (has1) {
                if (((S[L-1] >> b) & 1) != 1) {
                    possible = false;
                    break;
                }
            }
        }
        ans += (possible ? '1' : '0');
    }
    cout << ans << "\n";
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

