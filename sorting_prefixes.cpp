#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

void solve() {
    int N;
    if (!(cin >> N)) return;
    vector<int> A(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
    }

    long long min_cost = LLONG_MAX;

    for (int p = 0; p <= N; ++p) {
        bool suffix_ok = true;
        for (int i = p + 1; i <= N; ++i) {
            if (A[i] != i) {
                suffix_ok = false;
                break;
            }
        }

        if (suffix_ok) {
            long long cost = 0;
            if (p > 0) {
                cost = A[p];
            }
            if (cost < min_cost) {
                min_cost = cost;
            }
        }
    }

    cout << min_cost << endl;
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
