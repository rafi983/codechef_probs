#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    vector<int> bad_indices;
    for (int i = 0; i < N - 1; ++i) {
        if (S[i] == S[i+1]) {
            bad_indices.push_back(i);
        }
    }

    int K = bad_indices.size();

    if (K == 0) {
        cout << "Yes" << endl;
    } else if (K == 1) {
        int idx = bad_indices[0];
        char val = S[idx];
        if (S[0] != val || S[N-1] != val) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    } else if (K == 2) {
        int idx1 = bad_indices[0];
        int idx2 = bad_indices[1];

        if (S[idx1] != S[idx2]) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    } else {
        cout << "No" << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}

