#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


struct ItemCost {
    int p, q;
};

long long eval_dual(const vector<ItemCost>& I0, const vector<ItemCost>& I1, long long lam1, long long lam2) {
    long long total = 0;

    for (const auto& item : I0) {
        long long v1 = item.p + lam1;
        long long v2 = item.q + lam2;
        if (v1 < 0 || v2 < 0) {
            total += min(v1, v2);
        }
    }

    for (const auto& item : I1) {
        long long v1 = item.p - lam1;
        long long v2 = item.q - lam2;
        if (v1 < 0 || v2 < 0) {
            total += min(v1, v2);
        }
    }

    return total;
}

void solve() {
    int N;
    if (!(cin >> N)) return;
    string A, B, C;
    cin >> A >> B >> C;

    vector<ItemCost> I0, I1;
    long long base_cost = 0;

    for (int i = 0; i < N; ++i) {
        int a = A[i] - '0';
        int b = B[i] - '0';
        int c = C[i] - '0';

        if (b != c) base_cost++;

        if (c == 0) {
            // I0
            // p = a + 1 - 2b
            // q = 2 - a - 2b
            I0.push_back({a + 1 - 2*b, 2 - a - 2*b});
        } else {
            // I1
            // p = a + 2b - 1
            // q = 2b - a
            I1.push_back({a + 2*b - 1, 2*b - a});
        }
    }


    long long low1 = -400000, high1 = 400000;

    while (high1 - low1 > 2) {
        long long m1 = low1 + (high1 - low1) / 3;
        long long m2 = high1 - (high1 - low1) / 3;

        // Inner ternary search for m1
        long long l2 = -400000, h2 = 400000;
        while (h2 - l2 > 2) {
            long long n1 = l2 + (h2 - l2) / 3;
            long long n2 = h2 - (h2 - l2) / 3;
            if (eval_dual(I0, I1, m1, n1) < eval_dual(I0, I1, m1, n2)) {
                l2 = n1;
            } else {
                h2 = n2;
            }
        }
        long long val1 = -2e18; // -inf
        for (long long k = l2; k <= h2; ++k) val1 = max(val1, eval_dual(I0, I1, m1, k));

        // Inner ternary search for m2
        l2 = -400000; h2 = 400000;
        while (h2 - l2 > 2) {
            long long n1 = l2 + (h2 - l2) / 3;
            long long n2 = h2 - (h2 - l2) / 3;
            if (eval_dual(I0, I1, m2, n1) < eval_dual(I0, I1, m2, n2)) {
                l2 = n1;
            } else {
                h2 = n2;
            }
        }
        long long val2 = -2e18;
        for (long long k = l2; k <= h2; ++k) val2 = max(val2, eval_dual(I0, I1, m2, k));

        if (val1 < val2) {
            low1 = m1;
        } else {
            high1 = m2;
        }
    }

    long long ans = -2e18;
    for (long long lam1 = low1; lam1 <= high1; ++lam1) {
         // Optimize lam2 for this lam1
        long long l2 = -400000, h2 = 400000;
        while (h2 - l2 > 2) {
            long long n1 = l2 + (h2 - l2) / 3;
            long long n2 = h2 - (h2 - l2) / 3;
            if (eval_dual(I0, I1, lam1, n1) < eval_dual(I0, I1, lam1, n2)) {
                l2 = n1;
            } else {
                h2 = n2;
            }
        }
        long long best_inner = -2e18;
        for (long long k = l2; k <= h2; ++k) best_inner = max(best_inner, eval_dual(I0, I1, lam1, k));
        ans = max(ans, best_inner);
    }

    cout << base_cost + ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    if (cin >> T) {
        while(T--) {
            solve();
        }
    }
    return 0;
}
