#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int N;
    long long K;
    cin >> N >> K;
    vector<int> A(N);
    vector<int> counts(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        if (A[i] <= N) {
            counts[A[i]]++;
        }
    }

    int m = 0;
    vector<bool> in_P(K, false);
    int total_P = 0;

    for (int i = 0; i < K; ++i) {
        if (counts[i] == 0) {
            m++;
        } else {
            in_P[i] = true;
            total_P++;
        }
    }

    int min_missing_P = total_P; // Initialize with max possible missing

    vector<int> segment_counts(K, 0);
    int distinct_in_segment = 0;
    vector<int> seen_in_segment;

    for (int i = 0; i < N; ++i) {
        if (A[i] == K) {
            // End of segment
            int missing = total_P - distinct_in_segment;
            if (missing < min_missing_P) {
                min_missing_P = missing;
            }

            // Reset for next segment
            for (int x : seen_in_segment) {
                segment_counts[x] = 0;
            }
            seen_in_segment.clear();
            distinct_in_segment = 0;
        } else {
            if (A[i] < K && in_P[A[i]]) {
                if (segment_counts[A[i]] == 0) {
                    distinct_in_segment++;
                    seen_in_segment.push_back(A[i]);
                }
                segment_counts[A[i]]++;
            }
        }
    }
    // Check last segment
    int missing = total_P - distinct_in_segment;
    if (missing < min_missing_P) {
        min_missing_P = missing;
    }

    cout << m + min_missing_P + 1 << endl;
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
