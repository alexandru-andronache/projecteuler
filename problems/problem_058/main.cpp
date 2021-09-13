#include "math_common.h"
#include <cmath>
#include <iostream>

namespace problem_058 {
    int solve() {
        int size = 1;
        int diff = 2;
        int current = 1;
        int total = 1;
        int primes = 0;

        while (true) {
            size += 2;
            for (int i = 1; i <= 4; ++i) {
                primes += math::isPrime(current + i * diff);
            }
            total += 4;
            current += 4 * diff;
            diff += 2;

            float procentage = (primes * 100.f) / total;
            if (procentage < 10.f) {
                return size;
            }
        }
    }
}

#ifndef TESTING
int main() {
    std::cout << "Solution : " << problem_058::solve(0) << std::endl;

    return 0;
}
#endif
