#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    long long N, M;
    if (!(cin >> N >> M)) return;

    vector<long long> ans;
    ans.push_back(N);

    for (int i = 0; i < 62; ++i) {
        if (!((N >> i) & 1)) {
            long long val = N | (1LL << i);
            if (val <= M) {
                ans.push_back(val);
            }
        }
    }

    if (ans.size() <= 1) {
        cout << -1 << "\n";
    } else {
        cout << ans.size() << "\n";
        for (int i = 0; i < ans.size(); ++i) {
            cout << ans[i] << (i == ans.size() - 1 ? "" : " ");
        }
        cout << "\n";
    }
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

