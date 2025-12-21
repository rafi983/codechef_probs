#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdint>

#ifdef _MSC_VER
#include <intrin.h>
#endif

using namespace std;

struct CustomBitset {
    vector<uint64_t> words;
    int n_bits;

    CustomBitset(int n) : n_bits(n) {
        words.resize((n + 63) / 64, 0);
    }

    void set(int b) {
        if (b < 0 || b >= n_bits) return;
        words[b / 64] |= (1ULL << (b % 64));
    }

    bool test(int b) const {
        if (b < 0 || b >= n_bits) return false;
        return (words[b / 64] >> (b % 64)) & 1ULL;
    }

    bool bitwise_or_check(const CustomBitset& other) {
        bool changed = false;
        for(size_t i=0; i<words.size(); ++i) {
            uint64_t old = words[i];
            words[i] |= other.words[i];
            if (words[i] != old) changed = true;
        }
        return changed;
    }

    template<typename Func>
    void for_each_set_bit_from(int start, Func func) const {
        int start_word = start / 64;
        int start_bit = start % 64;

        for (int i = start_word; i < words.size(); ++i) {
            uint64_t w = words[i];
            if (i == start_word) {
                w &= ~((1ULL << start_bit) - 1);
            }

            while (w) {
                int bit_idx;
                #ifdef _MSC_VER
                    unsigned long idx;
                    _BitScanForward64(&idx, w);
                    bit_idx = idx;
                #else
                    bit_idx = __builtin_ctzll(w);
                #endif

                int actual_bit = i * 64 + bit_idx;
                if (actual_bit >= n_bits) return;
                func(actual_bit);

                w &= ~(1ULL << bit_idx);
            }
        }
    }
};

void solve() {
    int N, X, Y;
    if (!(cin >> N >> X >> Y)) return;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];

    vector<int> sorted_vals;
    vector<CustomBitset> reachables;

    // Initial state: only X is reachable
    CustomBitset initial_set(X + 1);
    initial_set.set(X);
    reachables.push_back(initial_set);

    vector<int> good_prefixes;

    for (int k = 0; k < N; ++k) {
        int val = A[k];

        if (val <= Y) {
            break;
        }

        bool present = false;
        for(int v : sorted_vals) if(v == val) present = true;

        if (!present) {
            int idx = 0;
            while (idx < sorted_vals.size() && sorted_vals[idx] > val) {
                idx++;
            }
            sorted_vals.insert(sorted_vals.begin() + idx, val);

            // Create a copy to avoid reference invalidation during vector resize
            CustomBitset new_set = reachables[idx];
            reachables.insert(reachables.begin() + idx + 1, new_set);

            for (int j = idx; j < sorted_vals.size(); ++j) {
                int u = sorted_vals[j];
                const auto& prev_set = reachables[j];
                auto& curr_set = reachables[j+1];

                bool changed = curr_set.bitwise_or_check(prev_set);

                prev_set.for_each_set_bit_from(u, [&](int v) {
                    int res = v % u;
                    if (!curr_set.test(res)) {
                        curr_set.set(res);
                        changed = true;
                    }
                });

                if (!changed) break;
            }
        }

        if (reachables.back().test(Y)) {
            good_prefixes.push_back(k + 1);
        }
    }

    cout << good_prefixes.size() << endl;
    for (int i = 0; i < good_prefixes.size(); ++i) {
        cout << good_prefixes[i] << (i == good_prefixes.size() - 1 ? "" : " ");
    }
    cout << endl;
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
