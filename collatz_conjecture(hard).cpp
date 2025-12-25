#include <iostream>
#include <vector>

using namespace std;

bool is_good(long long n) {
    if (n == 1 || n == 2 || n == 3 || n == 6) return true;
    return (n % 4 == 0);
}

void solve() {
    long long N;
    if (!(cin >> N)) return;

    if (!is_good(N)) {
        cout << -1 << endl;
        return;
    }

    long long ops = 0;
    while (true) {
        if (N == 1) {
            ops += 0;
            break;
        }
        if (N == 2) {
            ops += 1;
            break;
        }
        if (N == 3) {
            ops += 1;
            break;
        }
        if (N == 6) {
            ops += 2;
            break;
        }

        long long half = N / 2;
        if (is_good(half)) {
            N = half;
            ops += 1;
        } else {
            N = half + 2;
            ops += 2;
        }
    }
    cout << ops << endl;
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
