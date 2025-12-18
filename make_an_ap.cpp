#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

long long gcd(long long a, long long b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

void solve() {
    int N;
    cin >> N;
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    long long common_gcd = 0;
    for (int i = 0; i < N - 1; ++i) {
        long long diff = A[i+1] - A[i];
        if (i == 0) {
            common_gcd = diff;
        } else {
            common_gcd = gcd(common_gcd, diff);
        }
    }

    long long total_diff = A[N-1] - A[0];
    long long num_terms = total_diff / common_gcd + 1;
    long long operations = num_terms - N;

    cout << operations << endl;
}

int main() {
    int T;
    if (cin >> T) {
        while (T--) {
            solve();
        }
    }
    return 0;
}
