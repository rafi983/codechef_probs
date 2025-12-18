#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int N;
    if (!(cin >> N)) return;
    vector<int> H(N);
    for (int i = 0; i < N; ++i) {
        cin >> H[i];
    }

    if (N < 2) {
        cout << "0\n";
        return;
    }

    int M = N - 1;
    vector<int> D(M);
    for (int i = 0; i < M; ++i) {
        D[i] = H[i+1] - H[i];
    }

    vector<int> P;
    for (int i = 0; i < M - 1; ++i) {
        if (D[i] != D[i+1]) {
            P.push_back(i);
        }
    }

    long long total_friendships = 0;
    int p_idx = 0;

    for (int l = 0; l < M; ++l) {
        while (p_idx < P.size() && P[p_idx] < l) {
            p_idx++;
        }

        int max_r;
        if (p_idx < P.size()) {
            if (p_idx + 1 < P.size()) {
                max_r = P[p_idx + 1];
            } else {
                max_r = M - 1;
            }
        } else {
            max_r = M - 1;
        }

        long long count = max_r - l + 1;
        if (count > 0) {
            total_friendships += count;
        }
    }
    cout << total_friendships << "\n";
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

