#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve() {
    int N, K;
    cin >> N >> K;

    if (K < N / 2) {
        cout << "-1" << endl;
        return;
    }

    string S = "";
    for (int i = 0; i < N; ++i) {
        if (i % 2 == 0) S += 'A';
        else S += 'B';
    }

    if (K == N) {
        cout << S << endl;
        cout << S << endl;
        return;
    }

    string T_base = "";
    for (int i = 0; i < N; ++i) {
        if (i % 2 == 0) T_base += 'B';
        else T_base += 'C';
    }

    string T = "";

    if (N % 2 != 0) { // Odd N
        if (K == N / 2) {
            T = T_base;
        } else {
            int X = 2 * K - N;
            T = S.substr(0, X) + T_base.substr(X);
        }
    } else { // Even N
        int X = 2 * K - N + 1;
        T = S.substr(0, X) + T_base.substr(X);
    }

    cout << S << endl;
    cout << T << endl;
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

