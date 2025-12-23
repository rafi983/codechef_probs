#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int N;
    long long X;
    if (!(cin >> N >> X)) return;
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];
    vector<long long> B(N);
    for (int i = 0; i < N; ++i) cin >> B[i];

    int k = 0;
    for (int i = 0; i < N; ++i) {
        long long limit_survive = X - A[i];
        if (k > limit_survive) {
            k = (int)limit_survive;
        }
        long long limit_parry = X - B[i];
        if (k <= limit_parry) {
            k++;
        }
    }
    cout << k << "\n";
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

