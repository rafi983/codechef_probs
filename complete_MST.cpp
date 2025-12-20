#include <iostream>
#include <algorithm>

using namespace std;

void solve() {
    long long N, M;
    if (!(cin >> N >> M)) return;

    long long total_edges = N * (N - 1) / 2;
    long long Z = total_edges - M; // Number of 0-weight edges


    long long C_min = max(1LL, N - Z);



    long long k_min = 1;
    long long low = 1, high = N;

    // Binary search for smallest k
    while (low <= high) {
        long long mid = low + (high - low) / 2;
        long long capacity = mid * (mid - 1) / 2;
        if (capacity >= Z) {
            k_min = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    long long C_max = N - k_min + 1;

    // W = C - 1
    // Range of W is [C_min - 1, C_max - 1]
    long long L = C_min - 1;
    long long R = C_max - 1;

    if (L > R) {
        cout << 0 << "\n";
    } else {
        long long count = R - L + 1;
        long long sum = (L + R) * count / 2;
        cout << sum << "\n";
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

