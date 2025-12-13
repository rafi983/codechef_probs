#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, X, Y;
        cin >> N >> X >> Y;

        int maxEarnings;
        if (2 * X >= Y) {
            maxEarnings = N * X;
        } else {
            maxEarnings = (N / 2) * Y + (N % 2) * X;
        }

        cout << maxEarnings << endl;
    }
    return 0;
}

