#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <cstdlib>

using namespace std;

void solve() {
    int N;
    if (!(cin >> N)) return;
    string S;
    cin >> S;

    // Total sum of lengths of all substrings
    // Formula: N*(N+1)*(N+2)/6
    long long total_len_sum = (long long)N * (N + 1) * (N + 2) / 6;

    long long M = N / 2;
    long long total_even_substrings = M * (N - M);


    vector<int> cnt(2 * N + 1, 0);

    int current_state = 0;
    cnt[0 + N]++;

    for (char c : S) {
        int next_state;
        if (current_state == 0) {
            if (c == '1') next_state = 1;
            else next_state = -1;
        } else if (current_state > 0) { // Ends in 1
            if (c == '1') {
                // Pop 1
                if (current_state == 1) next_state = 0;
                else next_state = -(current_state - 1);
            } else {
                // Push 0
                next_state = -(current_state + 1);
            }
        } else { // Ends in 0 (current_state < 0)
            if (c == '0') {
                // Pop 0
                if (current_state == -1) next_state = 0;
                else next_state = -current_state - 1;
            } else {
                // Push 1
                next_state = -current_state + 1;
            }
        }
        current_state = next_state;
        cnt[current_state + N]++;
    }

    long long reducible_count = 0;
    for (int x : cnt) {
        if (x > 1) {
            reducible_count += (long long)x * (x - 1) / 2;
        }
    }

    long long ans = total_len_sum - total_even_substrings + reducible_count;
    cout << ans << "\n";
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

