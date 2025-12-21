#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int N;
    if (!(cin >> N)) return;
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());

    long long ans = 1;
    long long MOD = 998244353;

    for (int i = 0; i < N; ++i) {
        long long choices = A[i] - i;
        if (choices <= 0) {
            ans = 0;
            break;
        }
        ans = (ans * choices) % MOD;
    }

    cout << ans << endl;
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

