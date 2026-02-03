#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Slot {
    int value;
    int day;
};

bool compareSlots(const Slot& a, const Slot& b) {
    return a.value > b.value;
}

void solve() {
    int N;
    if (!(cin >> N)) return;
    vector<int> A(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
    }

    vector<Slot> slots;
    for (int i = 1; i <= N; ++i) {
        slots.push_back({A[i], i});
        slots.push_back({A[i], i});
    }

    sort(slots.begin(), slots.end(), compareSlots);

    vector<bool> item_used(N + 1, false);
    long long total_profit = 0;

    for (const auto& slot : slots) {


        int best_item = -1;
        for (int i = slot.day; i >= 1; --i) {
            if (!item_used[i]) {
                best_item = i;
                break;
            }
        }

        if (best_item != -1) {
            item_used[best_item] = true;
            total_profit += slot.value;
        }
    }

    cout << total_profit << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    if (cin >> T) {
        while (T--) {
            solve();
        }
    }
    return 0;
}
