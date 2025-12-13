#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, D;
        cin >> N >> D;

        int switches = 0;
        bool holdingCloseRange = true;

        for (int i = 0; i < N; i++) {
            int distance;
            cin >> distance;

            bool needCloseRange = (distance <= D);

            if (needCloseRange != holdingCloseRange) {
                switches++;
                holdingCloseRange = needCloseRange;
            }
        }

        cout << switches << endl;
    }
    return 0;
}

