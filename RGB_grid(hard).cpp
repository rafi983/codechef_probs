#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N, M;
long long P;

const int MAX_STATES = 15625; // 5^6
const int MAX_MASKS = 729; // 3^6
int trans[MAX_STATES][MAX_MASKS];

bool is_valid_vertical(const vector<int>& col) {
    if (N < 3) return true;
    for (int i = 0; i <= N - 3; ++i) {
        if (col[i] == 0 && col[i+1] == 2 && col[i+2] == 1) return false; // RGB
        if (col[i] == 1 && col[i+1] == 2 && col[i+2] == 0) return false; // BGR
    }
    return true;
}

int next_state_transition(int prev_s, int char_val) {
    if (char_val == 0) { // Place R
        if (prev_s == 4) return -1; // BG + R -> BGR (Invalid)
        return 0; // R
    } else if (char_val == 1) { // Place B
        if (prev_s == 3) return -1; // RG + B -> RGB (Invalid)
        return 1; // B
    } else { // Place G
        if (prev_s == 0) return 3; // R -> RG
        if (prev_s == 1) return 4; // B -> BG
        return 2; // G
    }
}

long long power(long long base, long long exp) {
    long long res = 1;
    base %= P;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % P;
        base = (base * base) % P;
        exp /= 2;
    }
    return res;
}

void solve() {
    if (!(cin >> N >> M >> P)) return;

    if (N == 0 || M == 0) {
        cout << 0 << endl;
        return;
    }

    // Number of states: 5^N
    int num_states = 1;
    for (int i = 0; i < N; ++i) num_states *= 5;

    // Number of masks: 3^N
    int num_raw_masks = 1;
    for (int i = 0; i < N; ++i) num_raw_masks *= 3;

    // Filter valid masks
    vector<int> valid_masks;
    vector<vector<int>> mask_cols;
    valid_masks.reserve(num_raw_masks);
    mask_cols.reserve(num_raw_masks);

    for (int mask = 0; mask < num_raw_masks; ++mask) {
        vector<int> col(N);
        int temp = mask;
        for (int i = 0; i < N; ++i) {
            col[i] = temp % 3;
            temp /= 3;
        }
        if (is_valid_vertical(col)) {
            valid_masks.push_back(mask);
            mask_cols.push_back(col);
        }
    }

    int num_valid_masks = valid_masks.size();

    int row_trans[5][3];
    for(int s=0; s<5; ++s) {
        for(int c=0; c<3; ++c) {
            row_trans[s][c] = next_state_transition(s, c);
        }
    }


    for (int s = 0; s < num_states; ++s) {
        // Decode state
        int temp = s;

        int row_s[6];
        for(int i=0; i<N; ++i) {
            row_s[i] = temp % 5;
            temp /= 5;
        }

        for (int midx = 0; midx < num_valid_masks; ++midx) {
            const vector<int>& col = mask_cols[midx];
            int next_s = 0;
            int mult = 1;
            bool possible = true;

            for (int i = 0; i < N; ++i) {
                int ns = row_trans[row_s[i]][col[i]];
                if (ns == -1) {
                    possible = false;
                    break;
                }
                next_s += ns * mult;
                mult *= 5;
            }

            if (possible) trans[s][midx] = next_s;
            else trans[s][midx] = -1;
        }
    }



    vector<long long> dp(num_states, 0);



    for (int midx = 0; midx < num_valid_masks; ++midx) {
        const vector<int>& col = mask_cols[midx];
        int s = 0;
        int mult = 1;
        for (int i = 0; i < N; ++i) {
            int val = col[i];
            int st = (val == 0 ? 0 : (val == 1 ? 1 : 2));
            s += st * mult;
            mult *= 5;
        }
        dp[s]++;
    }

    // DP Steps
    for (int j = 2; j <= M; ++j) {
        vector<long long> next_dp(num_states, 0);

        for (int s = 0; s < num_states; ++s) {
            if (dp[s] == 0) continue;

            long long current_val = dp[s];
            if (current_val >= P) current_val %= P; // Ensure it's mod P

            for (int midx = 0; midx < num_valid_masks; ++midx) {
                int next_s = trans[s][midx];
                if (next_s != -1) {
                    next_dp[next_s] += current_val;
                    if (next_dp[next_s] >= P) next_dp[next_s] -= P; // optimization
                }
            }
        }
        dp = next_dp;
    }

    long long invalid_cnt = 0;
    for (int s = 0; s < num_states; ++s) {
        invalid_cnt += dp[s];
        if (invalid_cnt >= P) invalid_cnt -= P;
    }

    long long total = power(3, (long long)N * M);
    long long ans = (total - invalid_cnt + P) % P;
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}

