#include <iostream>
#include <string>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    if (!(std::cin >> t)) {
        return 0;
    }
    std::string line;
    std::getline(std::cin, line);

    while (t--) {
        int n;
        if (!(std::cin >> n)) {
            return 0;
        }
        std::getline(std::cin, line);

        std::vector<std::string> dirs;
        std::vector<std::string> roads;
        dirs.reserve(n);
        roads.reserve(n);

        for (int i = 0; i < n; ++i) {
            if (!std::getline(std::cin, line)) {
                return 0;
            }
            const std::size_t pos = line.find(" on ");
            if (pos == std::string::npos) {
                return 0;
            }
            dirs.emplace_back(line.substr(0, pos));
            roads.emplace_back(line.substr(pos + 4));
        }

        std::cout << "Begin on " << roads.back() << '\n';
        for (int i = n - 2; i >= 0; --i) {
            const bool nextWasLeft = dirs[i + 1] == "Left";
            std::cout << (nextWasLeft ? "Right" : "Left") << " on " << roads[i] << '\n';
        }

        if (t) {
            std::cout << '\n';
        }
    }

    return 0;
}

