#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve() {
    int N;
    if (!(cin >> N)) return;
    string S;
    cin >> S;

    int boys = 0;
    int girls = 0;
    int count = 0;

    for (char c : S) {
        if (c == 'B') {
            boys++;
        } else {
            girls++;
        }
        count++;
        if (boys > 2 * girls) {
            break;
        }
    }
    cout << count << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    if (cin >> T) {
        while (T--) {
            solve();
        }
    }
    return 0;
}

