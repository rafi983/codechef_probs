#include <iostream>
#include <vector>
#include <queue>
#include <numeric>

using namespace std;

void solve() {
    int N;
    if (!(cin >> N)) return;
    vector<int> P(N);
    for (int i = 0; i < N; ++i) {
        cin >> P[i];
        P[i]--; // 0-indexed
    }

    vector<bool> visited(N, false);
    priority_queue<long long, vector<long long>, greater<long long>> pq;

    for (int i = 0; i < N; ++i) {
        if (!visited[i]) {
            int curr = i;
            long long len = 0;
            while (!visited[curr]) {
                visited[curr] = true;
                curr = P[curr];
                len++;
            }
            pq.push(len);
        }
    }

    if (pq.size() <= 1) {
        cout << 0 << endl;
        return;
    }

    long long total_cost = 0;
    while (pq.size() > 1) {
        long long a = pq.top();
        pq.pop();
        long long b = pq.top();
        pq.pop();
        long long new_len = a + b;
        total_cost += new_len;
        pq.push(new_len);
    }

    cout << total_cost << endl;
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

