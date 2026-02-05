#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long power(long long base, long long exp) {
    long long res = 1;
    base %= 998244353;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % 998244353;
        base = (base * base) % 998244353;
        exp /= 2;
    }
    return res;
}

long long factorial[200005];

void precompute() {
    factorial[0] = 1;
    for (int i = 1; i <= 200000; i++) {
        factorial[i] = (factorial[i - 1] * i) % 998244353;
    }
}

void solve() {
    int N;
    if (!(cin >> N)) return;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());

    int max_len = 0;
    int current_len = 1;

    if (N == 0) max_len = 0;
    else {
        for (int i = 1; i < N; i++) {
            if (A[i] == A[i-1] + 1) {
                current_len++;
            } else {
                max_len = max(max_len, current_len);
                current_len = 1;
            }
        }
        max_len = max(max_len, current_len);
    }

    long long count_blocks = 0;
    current_len = 1;
    if (N > 0) {
        for (int i = 1; i < N; i++) {
            if (A[i] == A[i-1] + 1) {
                current_len++;
            } else {
                if (current_len == max_len) {
                    count_blocks++;
                }
                current_len = 1;
            }
        }
        if (current_len == max_len) {
            count_blocks++;
        }
    } else {
        count_blocks = 0;
    }

    long long ways_prefix = power(2, max_len - 1);
    long long ways_suffix = factorial[N - max_len];

    long long ans = (count_blocks * ways_prefix) % 998244353;
    ans = (ans * ways_suffix) % 998244353;

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precompute();
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}
