#include <iostream>
#include <algorithm>

using namespace std;

void solve() {
    long long B, G, X, Y, N;
    cin >> B >> G >> X >> Y >> N;

    if (X + Y > N) {
        cout << -1 << endl;
        return;
    }

    long long min_rooms = (B + G + N - 1) / N;

    long long max_rooms_by_boys = B / X;

    long long max_rooms_by_girls = G / Y;

    long long limit_rooms = min(max_rooms_by_boys, max_rooms_by_girls);

    if (min_rooms <= limit_rooms) {
        cout << min_rooms << endl;
    } else {
        cout << -1 << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}
