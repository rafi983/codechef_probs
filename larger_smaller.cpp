#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int N;
    if (!(cin >> N)) return;
    vector<int> A(N);
    int min_val = 200; // Constraints say A_i <= 100, so 200 is safe infinity
    int max_val = 0;   // Constraints say A_i >= 1
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        if (A[i] < min_val) min_val = A[i];
        if (A[i] > max_val) max_val = A[i];
    }


    int ans = max(0, max_val - min_val - 1);
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

