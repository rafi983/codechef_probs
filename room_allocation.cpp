#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void solve() {
    int N;
    cin >> N;
    int total_rooms = 0;
    for (int i = 0; i < N; ++i) {
        int A;
        cin >> A;

        total_rooms += (A + 1) / 2;
    }
    cout << total_rooms << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}

