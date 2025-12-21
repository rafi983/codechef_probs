#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int N;
    if (!(cin >> N)) return;
    vector<int> cnt(N, 0);
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        if (a >= 0 && a < N) {
            cnt[a]++;
        }
    }

    long long ans = 1;
    long long MOD = 998244353;

    // Check pairs
    for (int i = 0; i < N / 2; ++i) {
        int j = N - 1 - i;
        if (cnt[i] + cnt[j] != 2) {
            cout << 0 << endl;
            return;
        }
        ans = (ans * 2) % MOD;
    }

    // Check middle element if N is odd
    if (N % 2 == 1) {
        int mid = N / 2;
        if (cnt[mid] != 1) {
            cout << 0 << endl;
            return;
        }
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}

