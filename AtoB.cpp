#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void solve() {
    long long x1, y1, z1, x2, y2, z2, K;
    if (!(cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2 >> K)) return;

    long long dx = abs(x1 - x2);
    long long dy = abs(y1 - y2);
    long long dz = abs(z1 - z2);

    vector<long long> d = {dx, dy, dz};
    sort(d.begin(), d.end(), greater<long long>());

    long long N = d[0];
    long long R = d[1] + d[2];

    if (N == 0) {
        cout << 0 << endl;
        return;
    }

    long long chunks = (N + K - 1) / K;
    long long needed = chunks - 1;

    if (needed <= R) {
        cout << (N + R) << endl;
    } else {
        long long missing = needed - R;
        long long extra = missing + (missing % 2);
        cout << (N + R + extra) << endl;
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

