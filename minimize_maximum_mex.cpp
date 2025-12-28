#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int N;
    if (!(cin >> N)) return;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N; ++i) cin >> B[i];

    vector<int> cnt2(N + 2, 0);
    vector<int> total_count(N + 2, 0);

    for (int i = 0; i < N; ++i) {
        total_count[A[i]]++;
        total_count[B[i]]++;
        if (A[i] == B[i]) {
            cnt2[A[i]]++;
        }
    }

    int z1 = -1;
    for (int i = 0; i <= N + 1; ++i) {
        if (cnt2[i] == 0) {
            if (z1 == -1) {
                z1 = i;
                if (total_count[i] == 0) {
                    cout << i << "\n";
                    return;
                }
            } else {
                cout << i << "\n";
                return;
            }
        }
    }
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

