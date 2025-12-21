#include <iostream>
#include <vector>
#include <queue>
#include <numeric>

using namespace std;

void solve() {
    int N;
    if (!(cin >> N)) return;
    vector<long long> A(2 * N);
    long long total_sum = 0;
    for (int i = 0; i < 2 * N; ++i) {
        cin >> A[i];
        total_sum += A[i];
    }

    // Min-priority queue to keep track of elements available to be discarded
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    long long discarded_sum = 0;

    for (int i = 0; i < N; ++i) {
        pq.push(A[2 * i]);
        pq.push(A[2 * i + 1]);

        discarded_sum += pq.top();
        pq.pop();
    }

    cout << total_sum - discarded_sum << endl;
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
