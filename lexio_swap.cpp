#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Block {
    char c;
    int len;
};

vector<Block> get_blocks(const string& s) {
    vector<Block> blocks;
    if (s.empty()) return blocks;

    char current_char = s[0];
    int current_len = 1;

    for (size_t i = 1; i < s.length(); ++i) {
        if (s[i] == current_char) {
            current_len++;
        } else {
            blocks.push_back({current_char, current_len});
            current_char = s[i];
            current_len = 1;
        }
    }
    blocks.push_back({current_char, current_len});
    return blocks;
}

void solve() {
    int N, M;
    if (!(cin >> N >> M)) return;
    string S, T;
    cin >> S >> T;

    vector<Block> blocksS = get_blocks(S);
    vector<Block> blocksT = get_blocks(T);

    if (blocksS.size() != blocksT.size()) {
        cout << "NO" << endl;
        return;
    }

    // Special case for single block
    if (blocksS.size() == 1) {
        if (S == T) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
        return;
    }

    for (size_t i = 0; i < blocksS.size(); ++i) {
        if (blocksS[i].c != blocksT[i].c) {
            cout << "NO" << endl;
            return;
        }
        if (blocksS[i].len < blocksT[i].len) {
            cout << "NO" << endl;
            return;
        }
        if ((blocksS[i].len - blocksT[i].len) % 2 != 0) {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int Q;
    if (cin >> Q) {
        while (Q--) {
            solve();
        }
    }
    return 0;
}

