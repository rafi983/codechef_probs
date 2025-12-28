#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main() {
    int N;
    if (cin >> N) {
        cout << 2 << endl;
        for (int i = 1; i <= N; ++i) {
            cout << i << (i == N ? "" : " ");
        }
        cout << endl;
        for (int i = N; i >= 1; --i) {
            cout << i << (i == 1 ? "" : " ");
        }
        cout << endl;
    }
    return 0;
}

