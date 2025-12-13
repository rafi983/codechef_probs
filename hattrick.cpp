#include <iostream>
#include <string>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        string balls[6];
        for (int i = 0; i < 6; i++) {
            cin >> balls[i];
        }

        bool hattrick = false;
        for (int i = 0; i <= 3; i++) {
            if (balls[i] == "W" && balls[i+1] == "W" && balls[i+2] == "W") {
                hattrick = true;
                break;
            }
        }

        cout << (hattrick ? "YES" : "NO") << endl;
    }
    return 0;
}

