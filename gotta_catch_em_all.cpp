#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, X, Y;
        cin >> N >> X >> Y;

        int totalCost = 0;
        for (int i = 0; i < N; i++) {
            int A;
            cin >> A;

            int normalCost = A * X;
            int masterCost = Y;

            totalCost += min(normalCost, masterCost);
        }

        cout << totalCost << endl;
    }
    return 0;
}
