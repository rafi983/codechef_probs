#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

// Function to print a string of '1's of length 2^h
void print_ones(int h) {
    if (h == 0) {
        cout << '1';
        return;
    }
    print_ones(h - 1);
    print_ones(h - 1);
}

void construct(int h, int k) {
    if (h == 0) {
        cout << (k ? '1' : '0');
        return;
    }

    int max_total = (1 << (h + 1)) - 1;
    if (k == max_total) {
        print_ones(h);
        return;
    }

    int max_sub = (1 << h) - 1;
    int r_sub = (1 << h) - h - 1;

    if (k >= max_sub) {

        print_ones(h - 1);
        // Print right child
        construct(h - 1, k - max_sub);
    } else {

        int val_left = min(k, r_sub);
        int val_right = k - val_left;

        construct(h - 1, val_left);
        construct(h - 1, val_right);
    }
}

void solve() {
    int N, K;
    if (!(cin >> N >> K)) return;

    int max_val = (1 << (N + 1)) - 1;
    int r_n = (1 << (N + 1)) - N - 2;

    if (K == max_val) {
        cout << "Yes" << endl;
        print_ones(N);
        cout << endl;
    } else if (K <= r_n) {
        cout << "Yes" << endl;
        construct(N, K);
        cout << endl;
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

