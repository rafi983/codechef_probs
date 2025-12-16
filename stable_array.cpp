#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

void solve() {
    int N;
    if (!(cin >> N)) return;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    vector<int> ans(N, 0);
    stack<int> st; // Stores indices

    for (int i = N - 1; i >= 0; --i) {
        while (!st.empty() && A[st.top()] < A[i]) {
            st.pop();
        }

        if (st.empty()) {
            ans[i] = 0;
        } else {
            int j = st.top();
            if (A[i] == A[j]) {
                if (ans[j] == 0) {
                    ans[i] = 0;
                } else {
                    ans[i] = ans[j] + (j - i);
                }
            } else {
                ans[i] = ans[j] + (j - i);
            }
        }
        st.push(i);
    }

    int max_seconds = 0;
    for (int x : ans) {
        max_seconds = max(max_seconds, x);
    }
    cout << max_seconds << endl;
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

