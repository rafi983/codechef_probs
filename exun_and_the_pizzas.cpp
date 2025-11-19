#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, K, R;
    if (!(cin >> N >> K >> R)) return 0;

    long long remaining = N - K;
    long long revenue = remaining * R;

    cout << revenue;
    return 0;
}

