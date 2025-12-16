#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int N;
    long long X;
    if (!(cin >> N >> X)) return;

    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    vector<long long> B(N);
    for (int i = 0; i < N; ++i) {
        cin >> B[i];
    }

    vector<long long> values(N);
    for (int i = 0; i < N; ++i) {
        values[i] = A[i] * B[i];
    }

    sort(values.rbegin(), values.rend());

    long long current_sum = 0;
    int types_count = 0;
    bool possible = false;

    for (int i = 0; i < N; ++i) {
        current_sum += values[i];
        types_count++;
        if (current_sum >= X) {
            possible = true;
            break;
        }
    }

    if (possible) {
        cout << types_count << endl;
    } else {
        cout << -1 << endl;
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

