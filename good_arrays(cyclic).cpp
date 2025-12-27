#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int MOD = 1e9 + 7;

void solve() {
    int N;
    if (!(cin >> N)) return;
    vector<string> M(N);
    for (int i = 0; i < N; ++i) {
        cin >> M[i];
    }

    long long total_valid = 1;
    for (int i = 0; i < N; ++i) {
        int count = 0;
        for (char c : M[i]) {
            if (c == '1') count++;
        }
        total_valid = (total_valid * count) % MOD;
    }

    long long bad_arrays = 1;
    int K = N / 2;
    for (int i = 0; i < K; ++i) {
        int count = 0;
        for (int j = 0; j < N; ++j) {
            if (M[i][j] == '1' && M[i + K][j] == '1') {
                count++;
            }
        }
        bad_arrays = (bad_arrays * count) % MOD;
    }

    long long ans = (total_valid - bad_arrays + MOD) % MOD;
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

