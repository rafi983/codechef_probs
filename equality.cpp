#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int N;
        if (!(cin >> N)) return 0;
        vector<long long> a(N);
        long long sum = 0;
        for (int i = 0; i < N; ++i) {
            cin >> a[i];
            sum += a[i];
        }
        long long S = sum / (N - 1);
        for (int i = 0; i < N; ++i) {
            if (i) cout << ' ';
            cout << (S - a[i]);
        }
        cout << '\n';
    }
    return 0;
}

