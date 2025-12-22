#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int memo[22][22][22];

// Returns 1 if current player wins, 0 if loses
int solve(int x, int y, int last_move) {
    if (memo[x][y][last_move] != -1) {
        return memo[x][y][last_move];
    }


    bool can_win = false;
    int max_stones = max(x, y);

    for (int s = last_move + 1; s <= max_stones; ++s) {
        // Try removing s from x
        if (s <= x) {
            if (!solve(x - s, y, s)) {
                can_win = true;
                break;
            }
        }
        // Try removing s from y
        if (s <= y) {
            if (!solve(x, y - s, s)) {
                can_win = true;
                break;
            }
        }
    }

    return memo[x][y][last_move] = (can_win ? 1 : 0);
}

void run_test_case() {
    int X, Y, K;
    cin >> X >> Y >> K;



    bool alice_wins = false;

    // Try removing from X
    for (int s = 1; s <= K; ++s) {
        if (s <= X) {
            if (!solve(X - s, Y, s)) {
                alice_wins = true;
                break;
            }
        }
        // Try removing from Y
        if (s <= Y) {
            if (!solve(X, Y - s, s)) {
                alice_wins = true;
                break;
            }
        }
    }

    if (alice_wins) {
        cout << "Alice" << endl;
    } else {
        cout << "Bob" << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(memo, -1, sizeof(memo));

    int T;
    if (cin >> T) {
        while (T--) {
            run_test_case();
        }
    }
    return 0;
}

