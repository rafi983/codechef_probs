#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

void solve() {
    vector<int> A(5);
    int current_sum = 0;
    for (int i = 0; i < 5; ++i) {
        cin >> A[i];
        current_sum += A[i];
    }

    sort(A.begin(), A.end());

    int bribes = 0;
    int idx = 0;
    while (current_sum < 35) {
        // Replace the smallest value with 10
        // The increase is 10 - A[idx]
        current_sum += (10 - A[idx]);
        bribes++;
        idx++;
    }

    cout << bribes * 100 << endl;
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

