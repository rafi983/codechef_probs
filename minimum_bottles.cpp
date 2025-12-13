#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, X;
        cin >> N >> X;

        int totalWater = 0;
        for (int i = 0; i < N; i++) {
            int A;
            cin >> A;
            totalWater += A;
        }

        int minBottles = (totalWater + X - 1) / X;
        cout << minBottles << endl;
    }
    return 0;
}

