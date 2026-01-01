#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void zaman() {
    int N;
    if (!(cin >> N)) return;
    string S;
    cin >> S;

    vector<int> ones_indices;
    ones_indices.reserve(N);
    for (int i = 0; i < N; ++i) {
        if (S[i] == '1') {
            ones_indices.push_back(i);
        }
    }

    long long cnt1 = ones_indices.size();
    long long max_good_prefixes = min((long long)N, 2 * cnt1);

    if (max_good_prefixes == 0) {
        cout << "0 0" << endl;
        return;
    }

    long long R = (max_good_prefixes + 1) / 2;

    long long min_swaps = 0;
    int next_pos_limit = N + 10; // Initialize with a value larger than any valid index

    for (int i = R - 1; i >= 0; --i) {
        int limit_formula = 2 * i;

        int limit_next = next_pos_limit - 1;

        int limit_orig = ones_indices[i];

        int target_pos = min({limit_formula, limit_next, limit_orig});

        min_swaps += (limit_orig - target_pos);
        next_pos_limit = target_pos;
    }

    cout << max_good_prefixes << " " << min_swaps << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    if (cin >> T) {
        while (T--) {
            zaman();
        }
    }
    return 0;
}
