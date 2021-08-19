#include "sieve_eratosthenes.h"
#include <vector>
#include <iostream>

namespace problem_023 {
    unsigned long long solve() {
        const int MAX = 28123;
        std::vector<int> abundant;
        std::vector<bool> sums(MAX + 1, true);
        math::SieveEratosthenes se(MAX + 1);
        for (int i = 2; i <= MAX; ++i) {
            if (se.sumOfProperDivisors(i) > i) {
                abundant.push_back(i);
            }
        }

        for (int i = 0; i < abundant.size(); ++i) {
            for (int j = i; j < abundant.size(); ++j) {
                sums[abundant[i] + abundant[j]] = false;
            }
        }

        unsigned long long sum = 0;
        for (int i = 1; i < sums.size(); ++i) {
            sum += i * sums[i];
        }

        return sum;
    }
}

#ifndef TESTING
int main() {
    std::cout << "Solution : " << problem_023::solve() << std::endl;

    return 0;
}
#endif
