#include <bits/stdc++.h>
using namespace std;

static inline long long sq(long long x) { return x * x; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int subtaskId;
    if (!(cin >> subtaskId)) return 0;
    int T;
    cin >> T;
    while (T--) {
        long long x1, y1, x2, y2, x3, y3;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

        long long a2 = sq(x2 - x1) + sq(y2 - y1);
        long long b2 = sq(x3 - x2) + sq(y3 - y2);
        long long c2 = sq(x1 - x3) + sq(y1 - y3);

        string sideType;
        if (a2 == b2 || b2 == c2 || a2 == c2) sideType = "Isosceles";
        else sideType = "Scalene";

        if (subtaskId == 1) {
            cout << sideType << " triangle\n";
            continue;
        }

        array<long long,3> d{a2,b2,c2};
        sort(d.begin(), d.end());
        string angleType;
        long long s = d[0] + d[1];
        if (s == d[2]) angleType = "right";
        else if (s > d[2]) angleType = "acute";
        else angleType = "obtuse";

        cout << sideType << ' ' << angleType << " triangle\n";
    }
    return 0;
}
