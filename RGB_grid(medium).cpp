#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N, M;
long long P;

bool is_valid_vertical(const vector<int>& col) {
    if (N < 3) return true;
    for (int i = 0; i <= N - 3; ++i) {
        if (col[i] == 0 && col[i+1] == 2 && col[i+2] == 1) return false;
        if (col[i] == 1 && col[i+1] == 2 && col[i+2] == 0) return false;
    }
    return true;
}


int next_state_transition(int prev_s, int char_val) {
    if (char_val == 0) { // Place R
        if (prev_s == 4) return -1;
        return 0;
    } else if (char_val == 1) { // Place B
        if (prev_s == 3) return -1;
        return 1;
    } else { // Place G
        if (prev_s == 0) return 3;
        if (prev_s == 1) return 4;
        return 2;
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


    int num_states = 1;
    for (int i = 0; i < N; ++i) num_states *= 5;

    int num_masks = 1;
    for (int i = 0; i < N; ++i) num_masks *= 3;

    vector<vector<int>> mask_cols(num_masks, vector<int>(N));
    vector<bool> mask_valid(num_masks);

    for (int mask = 0; mask < num_masks; ++mask) {
        int temp = mask;
        for (int i = 0; i < N; ++i) {
            mask_cols[mask][i] = temp % 3;
            temp /= 3;
        }
        mask_valid[mask] = is_valid_vertical(mask_cols[mask]);
    }

    vector<long long> dp(num_states, 0);

    // Initial step: Process first column (j=1)
    for (int mask = 0; mask < num_masks; ++mask) {
        if (!mask_valid[mask]) continue;

        int current_state = 0;
        int multiplier = 1;
        for (int i = 0; i < N; ++i) {
            int val = mask_cols[mask][i];
            int s;
            if (val == 0) s = 0; // R
            else if (val == 1) s = 1; // B
            else s = 2; // G

            current_state += s * multiplier;
            multiplier *= 5;
        }
        dp[current_state] = (dp[current_state] + 1) % P;
    }

    // Process remaining columns
    for (int j = 2; j <= M; ++j) {
        vector<long long> next_dp(num_states, 0);

        for (int s = 0; s < num_states; ++s) {
            if (dp[s] == 0) continue;

            // Unpack previous row states
            int temp = s;
            vector<int> row_states(N);
            for (int i = 0; i < N; ++i) {
                row_states[i] = temp % 5;
                temp /= 5;
            }

            // Try adding each valid mask
            for (int mask = 0; mask < num_masks; ++mask) {
                if (!mask_valid[mask]) continue;

                int next_s = 0;
                int multiplier = 1;
                bool possible = true;

                for (int i = 0; i < N; ++i) {
                    int ns = next_state_transition(row_states[i], mask_cols[mask][i]);
                    if (ns == -1) {
                        possible = false;
                        break;
                    }
                    next_s += ns * multiplier;
                    multiplier *= 5;
                }

                if (possible) {
                    next_dp[next_s] = (next_dp[next_s] + dp[s]) % P;
                }
            }
        }
        dp = next_dp;
    }

    long long invalid_count = 0;
    for (int s = 0; s < num_states; ++s) {
        invalid_count = (invalid_count + dp[s]) % P;
    }

    long long total = power(3, (long long)N * M);
    long long ans = (total - invalid_count + P) % P;

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}

