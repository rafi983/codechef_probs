#include <iostream>
#include <string>
using namespace std;

static bool is_vowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n;
        cin >> n;
        string s;
        s.reserve(n);
        cin >> s;

        int max_consecutive = 0;
        int current = 0;
        for (int i = 0; i < n; ++i) {
            if (is_vowel(s[i])) {
                current = 0;
            } else {
                ++current;
                if (current > max_consecutive) {
                    max_consecutive = current;
                }
            }
        }

        cout << (max_consecutive >= 4 ? "NO" : "YES") << '\n';
    }
    return 0;
}
