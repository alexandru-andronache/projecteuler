#include <iostream>
#include <cmath>

namespace problem_009 {
    int solve(int sum) {
        for (int a = 1; a < sum; ++a) {
            for (int b = a + 1; b < sum - a; ++b) {
                int c = sum - a - b;
                if (std::pow(c, 2) == std::pow(a, 2) + std::pow(b , 2)) {
                    return a * b * c;
                }
            }
        }
        return 0;
    }
}

#ifndef TESTING
int main() {
    std::cout << "Solution : " << problem_009::solve(1000) << std::endl;

    return 0;
}
#endif
