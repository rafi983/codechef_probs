#include <iostream>

using namespace std;

void solve() {
    long long N, M, A, B;
    if (!(cin >> N >> M >> A >> B)) return;


    if (M < N * A || M > N * B) {
        cout << "No" << endl;
        return;
    }



    if ((M - N * A) % (B - A) == 0) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
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

