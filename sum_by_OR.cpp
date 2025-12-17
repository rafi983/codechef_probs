#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int N;
    if (!(cin >> N)) return;
    vector<int> A(N);
    vector<int> all_masks;
    all_masks.reserve(N * 16); // Max 15 submasks per number

    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        vector<int> bits;
        for (int b = 0; b < 30; ++b) {
            if ((A[i] >> b) & 1) {
                bits.push_back(b);
            }
        }

        int L = bits.size();
        // Iterate all non-empty subsets of bits
        for (int m = 1; m < (1 << L); ++m) {
            int mask = 0;
            for (int k = 0; k < L; ++k) {
                if ((m >> k) & 1) {
                    mask |= (1 << bits[k]);
                }
            }
            all_masks.push_back(mask);
        }
    }

    sort(all_masks.begin(), all_masks.end());

    long long S = 0;
    if (!all_masks.empty()) {
        int current_mask = all_masks[0];
        int count = 1;

        for (size_t i = 1; i < all_masks.size(); ++i) {
            if (all_masks[i] != current_mask) {
                int set_bits = __builtin_popcount(current_mask);
                long long term = (long long)count * count;
                if (set_bits % 2 == 1) {
                    S += term;
                } else {
                    S -= term;
                }
                current_mask = all_masks[i];
                count = 1;
            } else {
                count++;
            }
        }
        // Process last group
        int set_bits = __builtin_popcount(current_mask);
        long long term = (long long)count * count;
        if (set_bits % 2 == 1) {
            S += term;
        } else {
            S -= term;
        }
    }

    long long non_zeros = N; // Since A_i >= 1
    long long intersecting_pairs = (S - non_zeros) / 2;
    long long total_pairs = (long long)N * (N - 1) / 2;
    long long ans = total_pairs + intersecting_pairs;

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

