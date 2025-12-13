#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int getMaxStreak(vector<int>& problems) {
    int maxStreak = 0;
    int currentStreak = 0;

    for (int i = 0; i < problems.size(); i++) {
        if (problems[i] > 0) {
            currentStreak++;
            maxStreak = max(maxStreak, currentStreak);
        } else {
            currentStreak = 0;
        }
    }

    return maxStreak;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;

        vector<int> om(N), addy(N);

        for (int i = 0; i < N; i++) {
            cin >> om[i];
        }

        for (int i = 0; i < N; i++) {
            cin >> addy[i];
        }

        int omMaxStreak = getMaxStreak(om);
        int addyMaxStreak = getMaxStreak(addy);

        if (omMaxStreak > addyMaxStreak) {
            cout << "OM" << endl;
        } else if (addyMaxStreak > omMaxStreak) {
            cout << "ADDY" << endl;
        } else {
            cout << "DRAW" << endl;
        }
    }
    return 0;
}

