#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;

        int seconds;
        if (N <= 2) {
            seconds = N;
        } else if (N == 3) {
            seconds = 1;
        } else if (N % 2 == 1) {
            seconds = (N - 1) / 2;
        } else {
            seconds = N / 2 + 1;
        }

        cout << seconds << endl;
    }
    return 0;
}

