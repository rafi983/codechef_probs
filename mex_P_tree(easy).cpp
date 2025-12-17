#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

long long gcd(long long a, long long b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

const vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};

int get_mex_p(long long g) {
    for (int p : primes) {
        if (g % p != 0) {
            return p;
        }
    }
    return primes.back();
}

void dfs(int u, int p, long long current_gcd, long long &sum_mex, const vector<vector<int>> &adj, const vector<long long> &A) {
    long long next_gcd = gcd(current_gcd, A[u-1]);
    sum_mex += get_mex_p(next_gcd);

    for (int v : adj[u-1]) {
        if (v != p) {
            dfs(v, u, next_gcd, sum_mex, adj, A);
        }
    }
}

void solve() {
    int N;
    if (!(cin >> N)) return;

    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    vector<vector<int>> adj(N);
    for (int i = 0; i < N - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u-1].push_back(v);
        adj[v-1].push_back(u);
    }

    vector<long long> B(N);
    for (int i = 1; i <= N; ++i) {
        long long sum_mex = 0;
        dfs(i, -1, 0, sum_mex, adj, A);
        B[i-1] = sum_mex;
    }

    for (int i = 0; i < N; ++i) {
        cout << B[i] << (i == N - 1 ? "" : " ");
    }
    cout << "\n";
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
