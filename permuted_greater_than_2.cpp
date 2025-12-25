#include <iostream>
using namespace std;

void solve() {
    int X, Y, Z;
    cin >> X >> Y >> Z;


    int slots_needed_for_zeros = X;
    int slots_needed_for_ones = (Y > 0) ? 1 : 0;

    int total_slots_needed = slots_needed_for_zeros + slots_needed_for_ones;
    int total_slots_available = Z + 1;

    if (total_slots_available >= total_slots_needed) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
