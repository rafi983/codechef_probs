#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Function to check if a vector is smoothly increasing
bool is_smoothly_increasing(vector<long long> b) {
    int n = b.size();
    while (n > 1) {
        for (int i = 0; i < n - 1; ++i) {
            long long diff = b[i+1] - b[i];
            if (diff <= 0) return false;
            b[i] = diff;
        }
        n--;
    }
    return true;
}

void solve() {
    int N;
    if (!(cin >> N)) return;
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    if (N > 40) {
        for (int i = 0; i < N; ++i) cout << '0';
        cout << "\n";
        return;
    }

    string ans = "";
    // Pre-allocate B to avoid reallocations
    vector<long long> B;
    B.reserve(N - 1);

    for (int i = 0; i < N; ++i) {
        B.clear();
        for (int j = 0; j < N; ++j) {
            if (i == j) continue;
            B.push_back(A[j]);
        }
        if (is_smoothly_increasing(B)) {
            ans += '1';
        } else {
            ans += '0';
        }
    }
    cout << ans << "\n";
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

