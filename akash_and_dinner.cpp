#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

#define MAXA 100000


int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;

        vector<int> A(N);
        vector<int> B(N);

        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }
        for (int i = 0; i < N; ++i) {
            cin >> B[i];
        }

        static int minB[MAXA + 1];
        for (int i = 0; i <= MAXA; ++i) {
            minB[i] = INT_MAX;
        }

        for (int i = 0; i < N; ++i) {
            int c = A[i];
            int t = B[i];
            if (t < minB[c]) {
                minB[c] = t;
            }
        }

        vector<int> vals;
        for (int c = 1; c <= MAXA; ++c) {
            if (minB[c] != INT_MAX) {
                vals.push_back(minB[c]);
            }
        }

        int m = vals.size();
        if (m < K) {
            cout << "-1\n";
        } else {
            sort(vals.begin(), vals.end());
            long long sum = 0;
            for (int i = 0; i < K; ++i) {
                sum += vals[i];
            }
            cout << sum << "\n";
        }
    }
    return 0;
}
