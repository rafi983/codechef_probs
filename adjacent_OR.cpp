#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int N;
    if (!(cin >> N)) return;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N; ++i) cin >> B[i];

    // Check ends
    if (A[0] != B[0] || A[N - 1] != B[N - 1]) {
        cout << "No" << endl;
        return;
    }

    for (int i = 0; i < N - 1; ++i) {
        if (A[i] == 1 && A[i + 1] == 1) {
            if (B[i] != 1 || B[i + 1] != 1) {
                cout << "No" << endl;
                return;
            }
        }
    }

    bool in_segment = false;
    bool has_one_in_A = false;
    for (int i = 0; i < N; ++i) {
        if (B[i] == 1) {
            if (!in_segment) {
                in_segment = true;
                has_one_in_A = false;
            }
            if (A[i] == 1) {
                has_one_in_A = true;
            }
        } else {
            if (in_segment) {
                if (!has_one_in_A) {
                    cout << "No" << endl;
                    return;
                }
                in_segment = false;
            }
        }
    }
    // Check last segment if it ends at N-1
    if (in_segment && !has_one_in_A) {
        cout << "No" << endl;
        return;
    }

    cout << "Yes" << endl;
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
