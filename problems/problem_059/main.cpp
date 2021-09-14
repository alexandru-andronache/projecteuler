#include "file.h"
#include <vector>
#include <iostream>
#include <numeric>

namespace problem_059 {
    int solve() {
        std::string input = file::readFileAsString("../problems/problem_059/input/input.in");
        std::vector<int> numbers;
        int n = 0;
        int i = 0;
        while (i < input.size()) {
            if (input[i] >= '0' && input[i] <= '9') {
                n = n * 10 + input[i] - '0';
            }
            else {
                numbers.push_back(n);
                n = 0;
            }
            i++;
        }
        numbers.push_back(n);

        for (int i = 'a'; i <= 'z'; ++i) {
            for (int j = 'a'; j <= 'z'; ++j) {
                for (int k = 'a'; k <= 'z'; ++k) {
                    std::vector<int> keys {i, j, k};
                    std::string result;
                    bool valid = true;
                    for (int l = 0; l < numbers.size(); ++l) {
                        result += (numbers[l] ^ keys[l % keys.size()]);
                        // characters allowed 0-9, a-z, A-Z, space, ',"[]:/();.+
                        valid &= (result[l] >= '0' && result[l] <= '9') ||
                                 (result[l] >= 'a' && result[l] <= 'z') ||
                                 (result[l] >= 'A' && result[l] <= 'Z') ||
                                 (result[l] == ' ' || result[l] == '\'' || result[l] == ',' || result[l] == '"') ||
                                 (result[l] == '[' || result[l] == ']' || result[l] == ':' || result[l] == '/') ||
                                 (result[l] == '(' || result[l] == ')' || result[l] == ';' || result[l] == '.') ||
                                 (result[l] == '+');
                    }

                    if (valid) {
                        return std::accumulate(result.begin(), result.end(), 0);
                    }
                }
            }
        }
    }
}

#ifndef TESTING
int main() {
    std::cout << "Solution : " << problem_059::solve(0) << std::endl;

    return 0;
}
#endif
