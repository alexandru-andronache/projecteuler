#include <iostream>
#include <array>
#include <cmath>
#include <map>

namespace problem_062 {
    unsigned long long solve(int n) {
        const int N = 10000;
        std::map<std::array<int, 10>, std::pair<int, int>> numbers;

        for (int i = 2; i <= N; ++i) {
            unsigned long long nr = std::pow(i, 3);
            std::array<int, 10> number{0};
            while (nr > 0) {
                number[nr % 10]++;
                nr = nr / 10;
            }
            if (numbers.count(number) > 0) {
                numbers[number].second++;
            }
            else {
                numbers[number] = {i, 1};
            }
        }

        int min = std::numeric_limits<int>::max();
        for (const auto& c : numbers) {
            if (c.second.second == n) {
                min = std::min(min, c.second.first);
            }
        }

        return std::pow(min, 3);
    }
}

#ifndef TESTING
int main() {
    std::cout << "Solution : " << problem_062::solve(0) << std::endl;

    return 0;
}
#endif
