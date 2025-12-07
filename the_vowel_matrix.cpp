#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        string s;
        cin >> s;

        vector<int> vowelPos;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
                vowelPos.push_back(i);
            }
        }

        int totalVowels = vowelPos.size();
        int numPieces = totalVowels / k;

        long long ans = 1;

        for (int piece = 1; piece < numPieces; piece++) {
            int lastVowelOfPiece = vowelPos[piece * k - 1];
            int firstVowelOfNextPiece = vowelPos[piece * k];

            int choices = firstVowelOfNextPiece - lastVowelOfPiece;

            ans = (ans * choices) % MOD;
        }

        cout << ans << "\n";
    }

    return 0;
}
