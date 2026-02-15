#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

long long pairs(long long n) {
    return n * (n - 1) / 2;
}

void solve() {
    int N;
    if (!(cin >> N)) return;

    vector<int> count(N + 1, 0);

    long long current_ans = 0;
    long long max_freq = 0;

    int zeros = N;

    for (int i = 0; i < N; ++i) {
        int X, Y;
        cin >> X >> Y;

        if (count[Y] > 0) {
            current_ans -= pairs(count[Y]);
        }

        count[Y]++;
        zeros--;

        current_ans += pairs(count[Y]);

        if (count[Y] > max_freq) {
            max_freq = count[Y];
        }

        long long ans;
        if (max_freq == 0) {

            ans = pairs(zeros);
        } else {
            long long current_max_pairs = pairs(max_freq);

            long long potential_max_pairs = pairs(max_freq + zeros);

            ans = current_ans - current_max_pairs + potential_max_pairs;
        }

        cout << ans << (i == N - 1 ? "" : " ");
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

