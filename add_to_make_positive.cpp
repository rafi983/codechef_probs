#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

void solve() {
    int N;
    cin >> N;
    long long sum = 0;
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        sum += a;
    }

    if (sum >= 0) {
        cout << 0 << endl;
    } else {
        long long P = -sum;
        // We need ceil(P / N)
        long long X = (P + N - 1) / N;
        cout << X << endl;
    }
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
