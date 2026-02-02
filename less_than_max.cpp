#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int N;
    if (!(cin >> N)) return;

    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    vector<bool> present(N + 1, false);
    int count = 0;

    for (int x : A) {
        if (x == 1) {
            present[1] = true;
            count++;
        } else {
            if (present[x - 1]) {
                present[x] = true;
                count++;
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
