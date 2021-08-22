#include <iostream>

namespace problem_028 {
    unsigned long long solve(int n) {
        unsigned long long sum = 1;
        unsigned long long current = 1;
        unsigned long long diff = 2;
        for (int i = 0; i < n / 2; ++i) {
            for (int j = 0; j < 4; ++j) {
                current += diff;
                sum += current;
            }
            diff += 2;
        }
        return sum;
    }
}

#ifndef TESTING
int main() {
    std::cout << "Solution : " << problem_028::solve(0) << std::endl;

    return 0;
}
#endif
