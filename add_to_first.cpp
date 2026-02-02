#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int N;
    if (!(cin >> N)) return;
    vector<long long> A(N), B(N);
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N; ++i) cin >> B[i];

    long long prev_max = 0;
    for (int i = 0; i < N; ++i) {
        if (A[i] > B[i]) {
            cout << "No" << endl;
            return;
        }
        if (A[i] < B[i]) {

            if (A[i] <= prev_max) {
                cout << "No" << endl;
                return;
            }
        }
        prev_max = max(prev_max, A[i]);
    }
    cout << "Yes" << endl;
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
