#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int N;
        cin >> N;
        unordered_map<string, long long> mp;
        mp.reserve(static_cast<size_t>(N * 3 * 1.3));

        auto read_block = [&](int cnt){
            for (int i = 0; i < cnt; ++i) {
                string s; long long c;
                cin >> s >> c;
                mp[s] += c;
            }
        };

        read_block(N);
        read_block(N);
        read_block(N);

        vector<long long> totals;
        totals.reserve(mp.size());
        for (auto &kv : mp) totals.push_back(kv.second);
        sort(totals.begin(), totals.end());

        for (size_t i = 0; i < totals.size(); ++i) {
            if (i) cout << ' ';
            cout << totals[i];
        }
        cout << '\n';
    }
    return 0;
}

