#include <iostream>
#include <string>
using namespace std;

static bool is_valid_tag(const string &s) {
    const int len = static_cast<int>(s.size());
    if (len < 4) return false;
    if (!(s[0] == '<' && s[1] == '/')) return false;
    if (s[len - 1] != '>') return false;
    if (len - 3 <= 0) return false;
    for (int i = 2; i < len - 1; ++i) {
        char c = s[i];
        const bool lower = (c >= 'a' && c <= 'z');
        const bool digit = (c >= '0' && c <= '9');
        if (!(lower || digit)) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;
    string s;
    while (T--) {
        if (!(cin >> s)) return 0;
        cout << (is_valid_tag(s) ? "Success" : "Error") << '\n';
    }
    return 0;
}

