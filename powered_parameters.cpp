#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int N;
    if (!(cin >> N)) return;
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    long long count = 0;
    for (int i = 0; i < N; ++i) {
        if (A[i] == 1) {
            count += N;
        } else {
            long long power = A[i];
            for (int j = 0; j < N; ++j) {
                if (power > 1000000000) break;

                if (power <= A[j]) {
                    count++;
                }

                if (j < N - 1) {
                    power *= A[i];
                }
            }
        }
    }
    cout << count << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}
