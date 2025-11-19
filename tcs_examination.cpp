#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    if (!(std::cin >> t)) {
        return 0;
    }

    while (t--) {
        int dragon_dsa, dragon_toc, dragon_dm;
        int sloth_dsa, sloth_toc, sloth_dm;
        std::cin >> dragon_dsa >> dragon_toc >> dragon_dm;
        std::cin >> sloth_dsa >> sloth_toc >> sloth_dm;

        const int dragon_total = dragon_dsa + dragon_toc + dragon_dm;
        const int sloth_total = sloth_dsa + sloth_toc + sloth_dm;

        if (dragon_total > sloth_total) {
            std::cout << "Dragon\n";
        } else if (sloth_total > dragon_total) {
            std::cout << "Sloth\n";
        } else if (dragon_dsa > sloth_dsa) {
            std::cout << "Dragon\n";
        } else if (sloth_dsa > dragon_dsa) {
            std::cout << "Sloth\n";
        } else if (dragon_toc > sloth_toc) {
            std::cout << "Dragon\n";
        } else if (sloth_toc > dragon_toc) {
            std::cout << "Sloth\n";
        } else {
            std::cout << "Tie\n";
        }
    }

    return 0;
}

