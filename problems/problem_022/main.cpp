#include "file.h"
#include <vector>
#include <iostream>

namespace problem_022 {
    int getNameValue(std::string_view name) {
        int value = 0;
        for (const auto& c : name) {
            value += c - 'A' + 1;
        }
        return value;
    }
    int solve() {
        std::string input = file::readFileAsString("../problems/problem_022/input/input.in");
        std::vector<std::string> names;
        int i = 0;
        while (i < input.size()) {
            i++;
            std::string name;
            while (input[i] != '\"') {
                name += input[i];
                i++;
            }
            i = i + 2;
            names.push_back(name);
        }

        std::sort(names.begin(), names.end());

        int sol = 0;
        for (int i = 0; i < names.size(); ++i) {
            sol += (i + 1) * getNameValue(names[i]);
        }

        return sol;
    }
}

#ifndef TESTING
int main() {
    std::cout << "Solution : " << problem_022::solve(0) << std::endl;

    return 0;
}
#endif
