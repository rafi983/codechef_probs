#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve() {
    int N;
    if (!(cin >> N)) return;
    string S;
    cin >> S;

    int balance = 0;
    int zero_crossings = 0;
    for (char c : S) {
        if (c == '1') {
            balance++;
        } else {
            balance--;
        }
        if (balance == 0) {
            zero_crossings++;
        }
    }

    long long ans = (1LL << zero_crossings);
    cout << ans << endl;
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

