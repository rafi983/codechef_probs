#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int N;
    if (!(cin >> N)) return;

    vector<int> A(N + 1);
    for (int i = 0; i < N + 1; ++i) {
        cin >> A[i];
    }

    int min_loudness = 2e9;


    for (int i = 0; i < N; ++i) {
        int current_loudness = max(A[i], A[i+1]);
        min_loudness = min(min_loudness, current_loudness);
    }

    cout << min_loudness << endl;
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
