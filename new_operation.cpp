#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct MinMax {
    long long min_v;
    long long max_v;
};

vector<int> input_arr;
MinMax dp_cache[25][25];
bool is_computed[25][25];

MinMax zaman_recursive(int start_idx, int end_idx) {
    if (start_idx == end_idx) {
        return { (long long)input_arr[start_idx], (long long)input_arr[start_idx] };
    }

    if (is_computed[start_idx][end_idx]) {
        return dp_cache[start_idx][end_idx];
    }

    long long overall_min = -1;
    long long overall_max = -1;

    for (int k = start_idx; k < end_idx; ++k) {
        MinMax left_res = zaman_recursive(start_idx, k);
        MinMax right_res = zaman_recursive(k + 1, end_idx);

        long long current_val_min = left_res.min_v + 2 * right_res.min_v;
        long long current_val_max = left_res.max_v + 2 * right_res.max_v;

        if (overall_min == -1 || current_val_min < overall_min) {
            overall_min = current_val_min;
        }

        if (overall_max == -1 || current_val_max > overall_max) {
            overall_max = current_val_max;
        }
    }

    is_computed[start_idx][end_idx] = true;
    dp_cache[start_idx][end_idx] = { overall_min, overall_max };
    return dp_cache[start_idx][end_idx];
}

void zaman() {
    int N;
    if (!(cin >> N)) return;

    input_arr.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> input_arr[i];
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            is_computed[i][j] = false;
        }
    }

    MinMax result = zaman_recursive(0, N - 1);
    cout << result.min_v << " " << result.max_v << endl;
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
