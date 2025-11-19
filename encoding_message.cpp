#include <iostream>
#include <string>
using namespace std;

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

        for (int i = 0; i + 1 < n; i += 2) {
            swap(s[i], s[i + 1]);
        }
        for (int i = 0; i < n; ++i) {
            s[i] = char('z' - (s[i] - 'a'));
        }
        cout << s << '\n';
    }
    return 0;
}
