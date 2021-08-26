#include "sieve_eratosthenes.h"
#include <cmath>
#include <iostream>

namespace problem_046 {
    int solve() {
        math::SieveEratosthenes se(10000);
        int i = 3;
        while (true) {
            if (!se.isPrime(i)) {
                bool found = false;
                for (int j = 3; j <= i - 2; j += 2) {
                    if (se.isPrime(j)) {
                        int k = (i - j) / 2;
                        int p = std::sqrt(k);
                        if (p * p == k) {
                            found = true;
                        }
                    }
                }
                if (!found) {
                    return i;
                }
            }
            i = i + 2;
        }
        return 0;
    }
}

#ifndef TESTING
int main() {
    std::cout << "Solution : " << problem_046::solve(0) << std::endl;

    return 0;
}
#endif
