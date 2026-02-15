#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Ball {
    long long a;
    long long b;
};

bool compareBalls(const Ball& x, const Ball& y) {
    return x.a < y.a;
}

void solve() {
    int n;
    if (!(cin >> n)) return;
    vector<Ball> balls(n);
    for (int i = 0; i < n; ++i) cin >> balls[i].a;
    for (int i = 0; i < n; ++i) cin >> balls[i].b;

    sort(balls.begin(), balls.end(), compareBalls);

    int count = 0;


    Ball min_time_ball = {-1, -1};

    for (int i = n - 1; i >= 0; --i) {
        if (min_time_ball.a == -1) {
            min_time_ball = balls[i];
            count++;
        } else {


            long long lhs = balls[i].a * min_time_ball.b;
            long long rhs = min_time_ball.a * balls[i].b;

            if (lhs <= rhs) {
                count++;
                min_time_ball = balls[i];
            } else {
            }
        }
    }
    cout << count << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}


