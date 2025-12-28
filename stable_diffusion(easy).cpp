#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

bool is_stable(const vector<int>& S) {
    int M = S.size();
    vector<int> c(M + 4, 0);
    for (int i = 0; i < M; ++i) {
        if (S[i] == 2) c[i + 1] = 1;
    }

    vector<int> current_states;
    current_states.push_back(0); // Initial state: all zeros

    int K = (M + 1) / 2; // ceil(M/2)

    for (int j = 1; j <= K; ++j) {
        vector<int> next_states;
        bool visited[32] = {false};

        for (int state : current_states) {
            int pp_u = (state >> 4) & 1;
            int pp_v = (state >> 3) & 1;
            int p_u = (state >> 2) & 1;
            int p_v = (state >> 1) & 1;
            int h = state & 1;

            for (int c_u = 0; c_u <= 1; ++c_u) {
                for (int c_v = 0; c_v <= 1; ++c_v) {
                    if (j == K && (M % 2 != 0)) {
                        if (c_u != c_v) continue;
                    }

                    // Check Eq j-1
                    if (j > 1) {

                        int lhs = p_u + c[j - 2] * pp_u + c[j] * c_u;


                        int rhs = p_v + c[M + 1 - j] * c_v + c[M + 3 - j] * pp_v;

                        if (lhs != rhs) continue;
                    }

                    int next_h = h | c_u | c_v;
                    int next_state = (p_u << 4) | (p_v << 3) | (c_u << 2) | (c_v << 1) | next_h;

                    if (!visited[next_state]) {
                        visited[next_state] = true;
                        next_states.push_back(next_state);
                    }
                }
            }
        }
        current_states = next_states;
    }

    for (int state : current_states) {
        int pp_u = (state >> 4) & 1;
        int pp_v = (state >> 3) & 1;
        int p_u = (state >> 2) & 1;
        int p_v = (state >> 1) & 1;
        int h = state & 1;

        if (h == 0) continue;

        if (M % 2 == 0) {

            int lhs = p_u + c[K - 1] * pp_u + c[K + 1] * p_v;


            int rhs = p_v + c[K] * p_u + c[K + 2] * pp_v;

            if (lhs == rhs) return true;
        } else {
            return true;
        }
    }

    return false;
}

void solve() {
    int N;
    if (!(cin >> N)) return;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    int count = 0;
    for (int i = 0; i < N; ++i) {
        vector<int> S;
        for (int j = i; j < N; ++j) {
            S.push_back(A[j]);
            if (is_stable(S)) {
                count++;
            }
        }
    }
    cout << count << endl;
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

