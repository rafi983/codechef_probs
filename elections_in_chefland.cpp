#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int xa, xb, xc;
        cin >> xa >> xb >> xc;

        if (xa > 50) {
            cout << 'A' << '\n';
        } else if (xb > 50) {
            cout << 'B' << '\n';
        } else if (xc > 50) {
            cout << 'C' << '\n';
        } else {
            cout << "NOTA" << '\n';
        }
    }

    return 0;
}

