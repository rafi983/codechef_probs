#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    int chef_votes = 0;
    int antichef_votes = 0;
    int winning_ways = 0;

    for (int i = 0; i < N; ++i) {
        if (S[i] == '1') {
            chef_votes++;
        } else {
            antichef_votes++;
        }

        if (chef_votes > antichef_votes) {
            winning_ways++;
        }
    }

    cout << winning_ways << endl;
}

int main() {
    int T;
    if (cin >> T) {
        while (T--) {
            solve();
        }
    }
    return 0;
}
