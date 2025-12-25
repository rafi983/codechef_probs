#include <iostream>

using namespace std;

void solve() {
    long long N;
    cin >> N;

    if (N == 1 || N == 2 || N == 3 || N == 6) {
        cout << "Yes" << endl;
    } else if (N % 4 == 0) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
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
