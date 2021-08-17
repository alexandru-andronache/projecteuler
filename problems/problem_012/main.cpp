#include "sieve_eratosthenes.h"
#include <iostream>

namespace problem_012 {
    int solve(int n) {
        int i = 1;
        int sum = 0;
        math::SieveEratosthenes se(1000000);
        while (true) {
            sum += i;
            if (se.divisorCount(sum) > n) {
                return sum;
            }
            i++;
        }
    }
}

#ifndef TESTING
int main() {
    std::cout << "Solution : " << problem_012::solve(500) << std::endl;

    return 0;
}
#endif
