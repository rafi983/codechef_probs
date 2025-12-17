#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int N, C;
    if (!(cin >> N >> C)) return;
    string S;
    cin >> S;

    int freq[5] = {0};
    for (char c : S) {
        if (c >= 'A' && c <= 'E') {
            freq[c - 'A']++;
        }
    }

    int min_total_cost = 2e9; // Initialize with a large value

    // Iterate through all subsets of languages to learn
    // There are 5 languages, so 2^5 = 32 subsets
    for (int mask = 0; mask < 32; ++mask) {
        int learned_count = 0;
        int translator_uses = 0;

        for (int i = 0; i < 5; ++i) {
            if ((mask >> i) & 1) {
                learned_count++;
            } else {
                translator_uses += freq[i];
            }
        }

        int learned_cost = learned_count * C;
        int translator_cost = translator_uses * (translator_uses + 1) / 2;
        int current_total_cost = learned_cost + translator_cost;

        if (current_total_cost < min_total_cost) {
            min_total_cost = current_total_cost;
        }
    }

    cout << min_total_cost << endl;
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

