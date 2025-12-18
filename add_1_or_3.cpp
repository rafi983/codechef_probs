#include <iostream>

using namespace std;

void solve() {
    long long N, M;
    cin >> N >> M;


    if (M >= N && M <= 3 * N && (M - N) % 2 == 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    int T;
    if (cin >> T) {
        while (T--) {
            solve();
        }
    }
    return 0;
}
