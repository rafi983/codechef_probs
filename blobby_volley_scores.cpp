#include <iostream>
#include <string>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        string S;
        cin >> N >> S;

        int aliceScore = 0, bobScore = 0;
        char server = 'A';

        for (int i = 0; i < N; i++) {
            char winner = S[i];

            if (winner == server) {
                if (server == 'A') {
                    aliceScore++;
                } else {
                    bobScore++;
                }
            } else {
                server = winner;
            }
        }

        cout << aliceScore << " " << bobScore << endl;
    }
    return 0;
}

