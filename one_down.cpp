#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve() {
    int N;
    cin >> N;
    string S, T;
    cin >> S >> T;

    // Check if T is a subset of S (bitwise)
    // i.e., we cannot have S[i] == '0' and T[i] == '1'
    for (int i = 0; i < N; ++i) {
        if (S[i] == '0' && T[i] == '1') {
            cout << "No" << endl;
            return;
        }
    }

    // Count differences where S[i] == '1' and T[i] == '0'
    int diff_count = 0;
    for (int i = 0; i < N; ++i) {
        if (S[i] == '1' && T[i] == '0') {
            diff_count++;
        }
    }

    if (diff_count % 2 == 0) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}

