#include <iostream>

namespace problem_001 {
    int solve(int n) {
        int sum = 0;
        for (int i = 1; i < n; ++i) {
            if (i % 3 == 0 || i % 5 == 0) {
                sum += i;
            }
        }

        return sum;
    }
}

#ifndef TESTING
int main() {
    std::cout << "Part 1: " << problem_001::solve(1000) << std::endl;

    return 0;
}
#endif
