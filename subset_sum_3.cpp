#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int N;
    cin >> N;
    int c0 = 0, c1 = 0, c2 = 0;
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        if (a % 3 == 0) c0++;
        else if (a % 3 == 1) c1++;
        else c2++;
    }

    if (c0 > 0 || (c1 > 0 && c2 > 0) || c1 >= 3 || c2 >= 3) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
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

