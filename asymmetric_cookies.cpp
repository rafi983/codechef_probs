#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

bool check_bob_win(int k, long long r) {
    if (k >= 2) return false;

    // If k is 0 or 1, Bob wins if and only if r is odd.
    return (r % 2 != 0);
}

void solve() {
    int N;
    if (!(cin >> N)) return;
    int c1 = 0, c2 = 0, c3 = 0;
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        if (a == 1) c1++;
        else if (a == 2) c2++;
        else if (a == 3) c3++;
    }

    long long R = c1 + 2LL * c2;
    int K = c3;
    int winning_moves = 0;

    if (c1 + c2 > 0) {
        // Bob faces state (K, R-1)
        if (!check_bob_win(K, R - 1)) {
            winning_moves += (c1 + c2);
        }
    }

    if (c3 > 0) {
        // Bob faces state (K-1, R+2)
        if (!check_bob_win(K - 1, R + 2)) {
            winning_moves += c3;
        }
    }

    cout << winning_moves << endl;
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

