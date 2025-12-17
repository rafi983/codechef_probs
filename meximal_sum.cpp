#include <iostream>
#include <vector>
#include <numeric>
#include <set>
#include <algorithm>
#include <map>

using namespace std;

const long long INF_LL = 1e18;

void solve() {
    int N;
    if (!(cin >> N)) return;
    vector<int> A(N);
    map<int, int> counts;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        counts[A[i]]++;
    }

    int G = 0;
    while (counts.count(G)) {
        G++;
    }

    // Prefix sums
    vector<long long> P(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        P[i+1] = P[i] + A[i];
    }

    int min_L = -1;
    int max_R = -1;

    if (G == 0) {
        min_L = 1;
        max_R = N - 1;
    } else {
        // Find min_L
        set<int> s;
        for (int i = 0; i < N; ++i) {
            if (A[i] < G) s.insert(A[i]);
            if (s.size() == G) {
                min_L = i + 1; // 1-based index L
                break;
            }
        }

        // Find max_R
        s.clear();
        int suffix_start = -1;
        for (int i = N - 1; i >= 0; --i) {
            if (A[i] < G) s.insert(A[i]);
            if (s.size() == G) {
                suffix_start = i + 1; // 1-based index of start of suffix
                break;
            }
        }
        if (suffix_start != -1) {
            max_R = suffix_start - 1;
        }
    }

    if (min_L == -1 || max_R == -1 || min_L >= max_R) {
        cout << "-1 -1" << endl;
        return;
    }

    long long min_ans = INF_LL;
    long long max_ans = -INF_LL;

    long long current_min_P = INF_LL;
    long long current_max_P = -INF_LL;
    int current_L_limit = min_L - 1;

    if (G == 0) {
        for (int R = min_L + 1; R <= max_R; ++R) {
            int limit = R - 1;
            while (current_L_limit < limit) {
                current_L_limit++;
                current_min_P = min(current_min_P, P[current_L_limit]);
                current_max_P = max(current_max_P, P[current_L_limit]);
            }

            long long term = -2 * P[R] + P[N];
            min_ans = min(min_ans, 2 * current_min_P + term);
            max_ans = max(max_ans, 2 * current_max_P + term);
        }
    } else {
        vector<int> last_pos(G, -1);
        multiset<int> pos_set;
        for(int i=0; i<G; ++i) pos_set.insert(-1);

        for (int R = 1; R <= max_R; ++R) {
            int val = A[R-1];
            if (val < G) {
                int old_pos = last_pos[val];
                auto it = pos_set.find(old_pos);
                if (it != pos_set.end()) {
                    pos_set.erase(it);
                }
                last_pos[val] = R;
                pos_set.insert(R);
            }

            if (R <= min_L) continue;

            int min_pos = *pos_set.begin();
            int limit = min_pos - 1;

            if (limit < min_L) continue;

            while (current_L_limit < limit) {
                current_L_limit++;
                current_min_P = min(current_min_P, P[current_L_limit]);
                current_max_P = max(current_max_P, P[current_L_limit]);
            }

            if (current_L_limit >= min_L) {
                 long long term = -2 * P[R] + P[N];
                 min_ans = min(min_ans, 2 * current_min_P + term);
                 max_ans = max(max_ans, 2 * current_max_P + term);
            }
        }
    }

    if (min_ans == INF_LL) {
        cout << "-1 -1" << endl;
    } else {
        cout << min_ans << " " << max_ans << endl;
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

