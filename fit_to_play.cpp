#include <iostream>
#include <limits>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int N;
        if (!(cin >> N)) return 0;

        int min_so_far = 0;
        int max_diff = numeric_limits<int>::min();
        bool first = true;

        for (int i = 0; i < N; ++i) {
            int x;
            cin >> x;
            if (first) {
                min_so_far = x;
                first = false;
            } else {
                int diff = x - min_so_far;
                if (diff > max_diff) max_diff = diff;
                if (x < min_so_far) min_so_far = x;
            }
        }

        if (!first && max_diff > 0) {
            cout << max_diff << '\n';
        } else {
            cout << "UNFIT" << '\n';
        }
    }

    return 0;
}

