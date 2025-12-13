#include <iostream>
#include <climits>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;

        int minWaste = INT_MAX;

        for (int i = 0; i < N; i++) {
            int A;
            cin >> A;

            if (A >= K) {
                int waste = A % K;
                minWaste = min(minWaste, waste);
            }
        }

        if (minWaste == INT_MAX) {
            cout << -1 << endl;
        } else {
            cout << minWaste << endl;
        }
    }
    return 0;
}

