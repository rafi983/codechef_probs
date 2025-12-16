#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void solve() {
    int N;
    if (!(cin >> N)) return;
    vector<pair<int, int>> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i].first;
        A[i].second = i;
    }

    // Sort descending to determine ranks
    // Rank 0 is the largest element
    sort(A.begin(), A.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.first > b.first;
    });

    int ans = N;
    for (int i = 0; i < N - 1; ++i) {
        if (abs(A[i].second - A[i+1].second) == 1) {
            ans--;
        }
    }
    cout << ans << endl;
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

