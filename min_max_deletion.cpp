#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long calculate_contribution(int i, int N, const vector<int>& A) {
    if (i < 0 || i >= N) return 0;
    long long contrib = 0;
    // Left child check: A[i-1] > A[i]
    if (i > 0 && A[i-1] > A[i]) {
        contrib += A[i];
    }
    // Right child check: A[i+1] >= A[i]
    if (i < N - 1 && A[i+1] >= A[i]) {
        contrib += A[i];
    }
    return contrib;
}

void solve() {
    int N, Q;
    if (!(cin >> N >> Q)) return;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    long long current_score = 0;
    for (int i = 0; i < N; ++i) {
        current_score += calculate_contribution(i, N, A);
    }

    for (int q = 0; q < Q; ++q) {
        int idx;
        int val;
        cin >> idx >> val;
        --idx; // 0-based

        if (idx - 1 >= 0) current_score -= calculate_contribution(idx - 1, N, A);
        current_score -= calculate_contribution(idx, N, A);
        if (idx + 1 < N) current_score -= calculate_contribution(idx + 1, N, A);

        // Update value
        A[idx] = val;

        // Add new contributions
        if (idx - 1 >= 0) current_score += calculate_contribution(idx - 1, N, A);
        current_score += calculate_contribution(idx, N, A);
        if (idx + 1 < N) current_score += calculate_contribution(idx + 1, N, A);

        cout << current_score << "\n";
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

