#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int N;
        string S;
        cin >> N >> S;
        if ((int)S.size() != N) S = S.substr(0, N);

        int runsB = 0, runsW = 0;
        char prev = 0;
        for (int i = 0; i < N; ++i) {
            if (i == 0 || S[i] != prev) {
                if (S[i] == 'B') ++runsB; else ++runsW;
            }
            prev = S[i];
        }
        cout << min(runsB, runsW) << '\n';
    }
    return 0;
}

