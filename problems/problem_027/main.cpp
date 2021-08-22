#include "sieve_eratosthenes.h"
#include <iostream>

namespace problem_027 {
    int solve() {
        math::SieveEratosthenes se(1000000);
        int prod = 0;
        int maxN = 0;
        for (int a = -999; a < 1000; ++a) {
            for (int b = -1000; b <= 1000; ++b) {
                int n = 0;
                while (se.isPrime(n * n + a * n + b)) {
                    n++;
                }
                if (n > maxN) {
                    maxN = n;
                    prod = a * b;
                }
            }
        }
        return prod;
    }
}

#ifndef TESTING
int main() {
    std::cout << "Solution : " << problem_027::solve(0) << std::endl;

    return 0;
}
#endif
