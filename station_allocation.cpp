#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

void solve() {
    int N;
    if (!(cin >> N)) return;
    vector<long long> C(N);
    long long S = 0;
    for (int i = 0; i < N; ++i) {
        cin >> C[i];
        S += C[i];
    }
    sort(C.begin(), C.end());

    int Q;
    cin >> Q;
    vector<long long> results;
    results.reserve(Q);

    for (int i = 0; i < Q; ++i) {
        long long X, Y;
        cin >> X >> Y;

        long long A, B, base_cost;

        if (X + Y <= S) {
            base_cost = 0;
            A = X;
            B = S - Y;
        } else {
            base_cost = X + Y - S;
            A = S - Y;
            B = X;
        }


        auto it = lower_bound(C.begin(), C.end(), A);
        long long extra_cost = -1;

        // Check the element >= A
        if (it != C.end()) {
            long long val = *it;
            if (val <= B) {
                extra_cost = 0;
            } else {
                // val > B
                extra_cost = val - B;
            }
        }

        // Check the element < A
        if (it != C.begin()) {
            long long val = *prev(it);
            long long dist = A - val;
            if (extra_cost == -1 || dist < extra_cost) {
                extra_cost = dist;
            }
        }

        results.push_back(base_cost + extra_cost);
    }

    for (int i = 0; i < Q; ++i) {
        cout << results[i] << (i == Q - 1 ? "" : " ");
    }
    cout << "\n";
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

