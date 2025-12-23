#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;


long long findNext(long long Target, long long Base) {
    if ((Target & Base) == Base) {
        return Target;
    }


    long long diff = Base & ~Target;

    int k = 63 - __builtin_clzll(diff);

    long long mask_upper = ~((1LL << (k + 1)) - 1);
    long long mask_lower = (1LL << k) - 1;

    long long res = (Target & mask_upper) | (1LL << k) | (Base & mask_lower);
    return res;
}

bool check(int B, int N, const vector<long long>& A) {
    long long mask = (1LL << (B + 1)) - 1;
    long long prev = 0;

    for (int i = 0; i < N; ++i) {
        long long high = A[i] & ~mask;
        long long low = A[i] & mask;

        long long target = prev - high;
        if (target < 0) target = 0;

        if (target > mask) return false;

        long long L = findNext(target, low);

        if (L > mask) return false;

        prev = high + L;
    }
    return true;
}

void solve() {
    int N;
    if (!(cin >> N)) return;
    vector<long long> A(N);
    bool sorted = true;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        if (i > 0 && A[i] < A[i-1]) sorted = false;
    }

    if (sorted) {
        cout << 0 << "\n";
        return;
    }

    for (int B = 0; B <= 60; ++B) {
        if (check(B, N, A)) {
            cout << (1LL << B) << "\n";
            return;
        }
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

