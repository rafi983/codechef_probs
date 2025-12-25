#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int N;
    if (!(cin >> N)) return;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    vector<int> C(N);
    for (int i = 0; i < N; ++i) {
        cin >> C[i];
    }

    long long total_cost = 0;
    int current_min_C = 200; // C_i <= 100

    for (int i = 0; i < N; ++i) {
        if (i == 0) {
            current_min_C = C[i];
        } else {
            current_min_C = min(current_min_C, C[i]);
        }
        total_cost += (long long)A[i] * current_min_C;
    }

    cout << total_cost << endl;
}

int main() {
    int T;
    if (cin >> T) {
        while (T--) {
            solve();
        }
    }
    return 0;
}
