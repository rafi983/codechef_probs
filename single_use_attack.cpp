#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int H, X, Y;
        cin >> H >> X >> Y;

        int onlyRegular = (H + X - 1) / X;

        int withSpecial;
        if (H <= Y) {
            withSpecial = 1;
        } else {
            withSpecial = 1 + (H - Y + X - 1) / X;
        }

        cout << min(onlyRegular, withSpecial) << endl;
    }
    return 0;
}

