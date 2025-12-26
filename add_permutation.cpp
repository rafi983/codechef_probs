#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int N, K;
    cin >> N >> K;

    vector<int> P(N);


    for (int i = 1; i <= N; ++i) {
        if (i < K) {
            P[i-1] = i;
        } else {
            P[i-1] = N + K - i;
        }
    }

    for (int i = 0; i < N; ++i) {
        cout << P[i] << (i == N - 1 ? "" : " ");
    }
    cout << endl;
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

