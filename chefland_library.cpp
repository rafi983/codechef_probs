#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

void solve() {
    int N;
    cin >> N;
    map<int, int> day_penalties;
    for (int i = 1; i <= N; ++i) {
        int day;
        cin >> day;
        day_penalties[day] = max(day_penalties[day], i);
    }

    long long total_penalty = 0;
    for (auto const& [day, penalty] : day_penalties) {
        total_penalty += penalty;
    }
    cout << total_penalty << endl;
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

