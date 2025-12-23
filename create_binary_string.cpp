#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void solve() {
    int N, A, B, C, D;
    if (!(cin >> N >> A >> B >> C >> D)) return;

    long long max_coins = -1;

    // Iterate through all possible numbers of zeros (x)
    for (int x = 0; x <= N; ++x) {
        int ones = N - x;

        long long current_coins = (long long)A * x + (long long)B * ones + (long long)max(C, D) * x * ones;

        if (max_coins == -1 || current_coins > max_coins) {
            max_coins = current_coins;
        }
    }
    cout << max_coins << endl;
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
