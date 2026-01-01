#include <iostream>
#include <vector>

using namespace std;

void zaman() {
    int N;
    if (!(cin >> N)) return;

    if (N == 2) {
        cout << -1 << endl;
        return;
    }

    vector<vector<int>> grid(N, vector<int>(N, 0));


    for (int j = 0; j <= N - 2; ++j) {
        grid[0][j] = 1;
    }

    for (int i = 0; i <= N - 3; ++i) {
        grid[i][N - 2] = 1;
    }


    int r_start = N - 3;
    int c_start = N - 2;

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 2; ++j) {
            grid[r_start + i][c_start + j] = 1;
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << grid[i][j] << (j == N - 1 ? "" : " ");
        }
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (cin >> T) {
        while (T--) {
            zaman();
        }
    }
    return 0;
}
