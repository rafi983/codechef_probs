#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    if (!(std::cin >> T)) {
        return 0;
    }

    while (T--) {
        int A, B;
        std::cin >> A >> B;

        int limakTotal = 0;
        int bobTotal = 0;
        int turn = 1;

        while (true) {
            if (turn % 2 == 1) {
                if (limakTotal + turn > A) {
                    std::cout << "Bob\n";
                    break;
                }
                limakTotal += turn;
            } else {
                if (bobTotal + turn > B) {
                    std::cout << "Limak\n";
                    break;
                }
                bobTotal += turn;
            }
            ++turn;
        }
    }

    return 0;
}

