#include "file.h"
#include <vector>
#include <iostream>

namespace problem_013 {
    std::string solve() {
        std::vector<std::string> numbers = file::readFileAsArrayOfString("../problems/problem_013/input/input.in");
        std::string result;
        int prev = 0;
        for (int i = numbers[0].size() - 1; i >= 0; --i) {
            int nr = prev;
            for (const auto& line : numbers) {
                nr += line[i] - '0';
            }
            prev = nr / 10;
            nr = nr % 10;
            result += std::to_string(nr);
        }
        result += std::to_string(prev);

        std::reverse(result.begin(), result.end());
        return result.substr(0, 10);
    }
}

#ifndef TESTING
int main() {
    std::cout << "Solution : " << problem_013::solve(0) << std::endl;

    return 0;
}
#endif
