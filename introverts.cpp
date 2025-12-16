#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>

using namespace std;

int get_priority(int L, int R, int N) {
    if (L == 0 && R == N + 1) return 1e9;
    if (L == 0) return R - 1;
    if (R == N + 1) return N - L;
    return (R - L) / 2;
}

bool is_candidate(int seat, int L, int R, int N) {
    if (L == 0 && R == N + 1) {
        if (N == 1) return seat == 1;
        return seat == 1 || seat == N;
    }
    if (L == 0) return seat == 1;
    if (R == N + 1) return seat == N;
    int mid = (L + R) / 2;
    if ((R - L) % 2 == 0) return seat == mid;
    return seat == mid || seat == mid + 1;
}

void solve() {
    int N;
    if (!(cin >> N)) return;
    vector<int> P(N);
    vector<int> pos(N + 1);
    for (int i = 0; i < N; ++i) {
        cin >> P[i];
        pos[P[i]] = i + 1; // Person P[i] is at seat i+1? No.
        // P[i] is the person sitting in seat i+1.
        // We want to know where Person 1 sits, Person 2 sits...
        // Person k sits at seat j such that P[j-1] == k.
    }

    vector<int> seat_of_person(N + 1);
    for (int i = 0; i < N; ++i) {
        seat_of_person[P[i]] = i + 1;
    }

    set<pair<int, int>> intervals;
    multiset<int> priorities;

    intervals.insert({0, N + 1});
    priorities.insert(get_priority(0, N + 1, N));

    for (int k = 1; k <= N; ++k) {
        int u = seat_of_person[k];

        // Find interval containing u
        auto it = intervals.upper_bound({u, (int)2e9});
        if (it == intervals.begin()) {
            // Should not happen
            cout << "NO" << endl;
            return;
        }
        it--;

        int L = it->first;
        int R = it->second;

        if (u <= L || u >= R) {
            // Seat not in interval (should not happen if logic is correct)
            cout << "NO" << endl;
            return;
        }

        int current_prio = get_priority(L, R, N);
        int max_prio = *priorities.rbegin();

        if (current_prio != max_prio) {
            cout << "NO" << endl;
            return;
        }

        if (!is_candidate(u, L, R, N)) {
            cout << "NO" << endl;
            return;
        }

        // Remove current interval
        intervals.erase(it);
        priorities.erase(priorities.find(current_prio));

        // Add new intervals
        if (u > L + 1) {
            intervals.insert({L, u});
            priorities.insert(get_priority(L, u, N));
        }
        if (R > u + 1) {
            intervals.insert({u, R});
            priorities.insert(get_priority(u, R, N));
        }
    }

    cout << "YES" << endl;
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

