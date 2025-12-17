#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

struct Op {
    int type;
    int L, R;
};

int calculate_hamming(const string& s1, const string& s2, int start, int end) {
    int dist = 0;
    for (int i = start; i <= end; ++i) {
        if (s1[i] != s2[i]) {
            dist++;
        }
    }
    return dist;
}

vector<Op> solve_lr(int N, string A, string B) {
    vector<Op> ops;
    for (int i = 0; i < N; ++i) {
        if (A[i] == B[i]) continue;

        int best_choice = -1;
        int min_dist = N + 1;

        // Choice 1: Flip [i, i]
        {
            string temp = A;
            temp[i] = (temp[i] == '0' ? '1' : '0');
            int dist = calculate_hamming(temp, B, i + 1, N - 1);
            if (dist < min_dist) {
                min_dist = dist;
                best_choice = 1;
            }
        }

        // Choice 2: Flip [i, N-1]
        {
            string temp = A;
            for (int k = i; k < N; ++k) temp[k] = (temp[k] == '0' ? '1' : '0');
            int dist = calculate_hamming(temp, B, i + 1, N - 1);
            if (dist < min_dist) {
                min_dist = dist;
                best_choice = 2;
            }
        }

        // Choice 3: Reverse [i, N-1]
        if (A[N - 1] == B[i]) {
            string temp = A;
            reverse(temp.begin() + i, temp.end());
            int dist = calculate_hamming(temp, B, i + 1, N - 1);
            if (dist < min_dist) {
                min_dist = dist;
                best_choice = 3;
            }
        }

        if (best_choice == 1) {
            ops.push_back({1, i + 1, i + 1});
            A[i] = (A[i] == '0' ? '1' : '0');
        } else if (best_choice == 2) {
            ops.push_back({1, i + 1, N});
            for (int k = i; k < N; ++k) A[k] = (A[k] == '0' ? '1' : '0');
        } else if (best_choice == 3) {
            ops.push_back({2, i + 1, N});
            reverse(A.begin() + i, A.end());
        }
    }
    return ops;
}

vector<Op> solve_rl(int N, string A, string B) {
    vector<Op> ops;
    for (int i = N - 1; i >= 0; --i) {
        if (A[i] == B[i]) continue;

        int best_choice = -1;
        int min_dist = N + 1;

        // Choice 1: Flip [i, i]
        {
            string temp = A;
            temp[i] = (temp[i] == '0' ? '1' : '0');
            int dist = calculate_hamming(temp, B, 0, i - 1);
            if (dist < min_dist) {
                min_dist = dist;
                best_choice = 1;
            }
        }

        // Choice 2: Flip [0, i]
        {
            string temp = A;
            for (int k = 0; k <= i; ++k) temp[k] = (temp[k] == '0' ? '1' : '0');
            int dist = calculate_hamming(temp, B, 0, i - 1);
            if (dist < min_dist) {
                min_dist = dist;
                best_choice = 2;
            }
        }

        // Choice 3: Reverse [0, i]
        if (A[0] == B[i]) {
            string temp = A;
            reverse(temp.begin(), temp.begin() + i + 1);
            int dist = calculate_hamming(temp, B, 0, i - 1);
            if (dist < min_dist) {
                min_dist = dist;
                best_choice = 3;
            }
        }

        if (best_choice == 1) {
            ops.push_back({1, i + 1, i + 1});
            A[i] = (A[i] == '0' ? '1' : '0');
        } else if (best_choice == 2) {
            ops.push_back({1, 1, i + 1});
            for (int k = 0; k <= i; ++k) A[k] = (A[k] == '0' ? '1' : '0');
        } else if (best_choice == 3) {
            ops.push_back({2, 1, i + 1});
            reverse(A.begin(), A.begin() + i + 1);
        }
    }
    return ops;
}

void solve() {
    int N;
    if (!(cin >> N)) return;
    string A, B;
    cin >> A >> B;

    vector<Op> ops1 = solve_lr(N, A, B);
    vector<Op> ops2 = solve_rl(N, A, B);

    vector<Op> final_ops;
    if (ops1.size() <= (N + 1) / 2) {
        final_ops = ops1;
    } else {
        final_ops = ops2;
    }

    cout << final_ops.size() << endl;
    for (const auto& op : final_ops) {
        cout << op.type << " " << op.L << " " << op.R << endl;
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

