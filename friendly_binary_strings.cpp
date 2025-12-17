#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int N;
    if (!(cin >> N)) return;
    string A, B;
    cin >> A >> B;

    int c00 = 0;
    int c11 = 0;

    for (int i = 0; i < N; ++i) {
        if (A[i] == '0' && B[i] == '0') {
            c00++;
        } else if (A[i] == '1' && B[i] == '1') {
            c11++;
        }
    }

    if (N % 2 == 0) {
        if (c00 % 2 == 0 && c11 % 2 == 0) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    } else {
        if (c00 % 2 != 0 && c11 % 2 != 0) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
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
