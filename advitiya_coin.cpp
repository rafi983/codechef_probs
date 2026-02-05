#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int N;
    long long K;
    if (!(cin >> N >> K)) return;

    vector<long long> P(N);
    for(int i = 0; i < N; ++i) {
        cin >> P[i];
    }

    int count = 0;
    long long current_min = 0;
    long long current_max = 0;
    bool started = false;

    for (int i = 0; i < N; ++i) {
        if (!started) {
            current_min = P[i];
            current_max = P[i];
            started = true;
        } else {
            current_min = min(current_min, P[i]);
            current_max = max(current_max, P[i]);

            if (current_max - current_min > K) {
                count++;
                started = false;
            }
        }
    }

    cout << count << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t) {
        while(t--) {
            solve();
        }
    }
    return 0;
}
