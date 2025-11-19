#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int N;
        if (!(cin >> N)) return 0;

        vector<int> arrival(N);
        vector<int> depart(N);
        for (int i = 0; i < N; ++i) cin >> arrival[i];
        for (int i = 0; i < N; ++i) cin >> depart[i];

        sort(arrival.begin(), arrival.end());
        sort(depart.begin(), depart.end());

        int i = 0, j = 0, cur = 0, best = 0;
        while (i < N && j < N) {
            if (arrival[i] < depart[j]) {
                ++cur;
                if (cur > best) best = cur;
                ++i;
            } else {
                --cur;
                ++j;
            }
        }

        cout << best << '\n';
    }

    return 0;
}

