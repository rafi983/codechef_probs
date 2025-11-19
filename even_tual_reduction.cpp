#include <iostream>
#include <array>
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

        array<int, 26> freq{};
        for (char c : s) {
            ++freq[c - 'a'];
        }

        bool possible = true;
        for (int count : freq) {
            if (count % 2 != 0) {
                possible = false;
                break;
            }
        }

        cout << (possible ? "YES" : "NO") << '\n';
    }

    return 0;
}

