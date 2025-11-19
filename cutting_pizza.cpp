#include <bits/stdc++.h>
using namespace std;

static vector<int> build_divisors() {
    vector<int> divisors;
    for (int d = 1; d <= 360; ++d) {
        if (360 % d == 0) divisors.push_back(d);
    }
    return divisors;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;
    const vector<int> divisors = build_divisors();

    while (T--) {
        int n;
        if (!(cin >> n)) return 0;

        vector<int> angles(n);
        for (int &angle : angles) {
            cin >> angle;
        }

        sort(angles.begin(), angles.end());
        angles.erase(unique(angles.begin(), angles.end()), angles.end());
        if (angles.empty()) {
            cout << 0 << '\n';
            continue;
        }

        vector<int> gaps;
        gaps.reserve(angles.size());
        for (size_t i = 1; i < angles.size(); ++i) {
            gaps.push_back(angles[i] - angles[i - 1]);
        }
        gaps.push_back(360 - angles.back() + angles.front());

        int best = 360;
        for (int slices : divisors) {
            const int slice_angle = 360 / slices;
            int additions = 0;
            bool possible = true;
            for (int gap : gaps) {
                if (gap % slice_angle != 0) {
                    possible = false;
                    break;
                }
                additions += gap / slice_angle - 1;
                if (additions >= best) {
                    possible = false;
                    break;
                }
            }
            if (possible && additions < best) {
                best = additions;
            }
        }

        cout << best << '\n';
    }

    return 0;
}
