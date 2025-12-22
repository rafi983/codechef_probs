#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    vector<int> left_A(N, 0);
    vector<int> right_C(N, 0);

    int cnt = 0;
    for (int i = 0; i < N; ++i) {
        if (S[i] == 'A') {
            cnt++;
        } else if (S[i] == 'C') {
            cnt = 0;
        } else if (S[i] == 'B') {
            left_A[i] = cnt;
        }
    }

    cnt = 0;
    for (int i = N - 1; i >= 0; --i) {
        if (S[i] == 'C') {
            cnt++;
        } else if (S[i] == 'A') {
            cnt = 0;
        } else if (S[i] == 'B') {
            right_C[i] = cnt;
        }
    }

    long long ans = 0;
    for (int i = 0; i < N; ++i) {
        if (S[i] == 'B') {
            ans += max(left_A[i], right_C[i]);
        }
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

