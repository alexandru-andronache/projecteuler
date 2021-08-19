#include "file.h"
#include <iostream>
#include <vector>

namespace problem_018 {
    unsigned long long solve(std::string_view path) {
        std::vector<std::vector<int>> numbers = file::readFileAsArrayOfArrayOfInt(path);
        std::vector<std::vector<unsigned long long>> max(numbers.size());

        for (int i = 0; i < numbers.size(); ++i) {
            for (int j = 0; j < numbers[i].size(); ++j) {
                max[i].emplace_back(numbers[i][j]);
            }
        }

        for (int i = 1; i < numbers.size(); ++i) {
            max[i][0] += max[i - 1][0];
            for (int j = 1; j < numbers[i].size() - 1; ++j) {
                max[i][j] += std::max(max[i - 1][j - 1], max[i - 1][j]);
            }
            max[i].back() += max[i - 1].back();
        }

        return *std::max_element(max.back().begin(), max.back().end());
    }
}

#ifndef TESTING
int main() {
    std::cout << "Solution : " << problem_018::solve("../problems/problem_018/input/input.in") << std::endl;

    return 0;
}
#endif
