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

    long long count = 0;
    for (int L = 0; L < N; ++L) {
        int prev = -1;
        for (int R = L; R < N; ++R) {
            int limit = (A[R] - 1) / 2;
            int best = -1;

            // Candidate 1: smallest value in [0, limit] that is > prev
            // i.e. max(0, prev + 1). But must be <= limit.
            // Since prev >= -1, prev + 1 >= 0. So just prev + 1.
            if (prev + 1 <= limit) {
                best = prev + 1;
            }

            // Candidate 2: A[R] itself
            if (A[R] > prev) {
                if (best == -1 || A[R] < best) {
                    best = A[R];
                }
            }

            if (best != -1) {
                count++;
                prev = best;
            } else {
                break;
            }
        }
    }
    cout << count << endl;
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

