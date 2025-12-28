#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>

using namespace std;

void solve() {
    int N;
    long long K;
    if (!(cin >> N >> K)) return;
    vector<long long> A(N);
    long long current_sum = 0;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        current_sum += A[i];
    }
    sort(A.begin(), A.end());

    long long a1 = A[0];
    long long a2 = A[1];

    long long current_val = a2;
    for (long long k = 0; k < K; ++k) {
        long long next_val = (a1 + current_val + 1) / 2;
        if (next_val == current_val) {
            long long remaining_ops = K - k;
            current_sum += remaining_ops * next_val;
            break;
        }
        current_sum += next_val;
        current_val = next_val;
    }

    cout << current_sum << endl;
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

