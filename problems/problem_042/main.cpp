#include "file.h"
#include <vector>
#include <iostream>

namespace problem_042 {
    int solve() {
        std::string input = file::readFileAsString("../problems/problem_042/input/input.in");
        const int N = 50;
        std::vector<bool> triangleNumbers(N * (N + 1) / 2 + 1, false);
        int sol = 0;
        int i = 1;

        for (int j = 1, t = 0; j < N; ++j) {
            t += j;
            triangleNumbers[t] = true;
        }

        while (i < input.size()) {
            int sum = 0;
            while (input[i] >= 'A' && input[i] <= 'Z') {
                sum += input[i] - 'A' + 1;
                i++;
            }
            i = i + 3;
            sol += triangleNumbers[sum];
        }
        return sol;
    }
}

#ifndef TESTING
int main() {
    std::cout << "Solution : " << problem_042::solve() << std::endl;

    return 0;
}
#endif
