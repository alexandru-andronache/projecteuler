#include "sieve_eratosthenes.h"
#include <cmath>
#include <iostream>

namespace problem_035 {
    int solve(int n) {
        math::SieveEratosthenes se(n);
        int nr = 0;
        for (int i = 2; i < n; ++i) {
            int multiply = std::pow(10, std::to_string(i).length() - 1);
            int k = i;
            bool prime = false;
            if (se.isPrime(k)) {
                prime = true;
                do {
                    k = k / 10 + (k % 10) * multiply;
                    prime = prime && se.isPrime(k);
                }
                while (k != i && se.isPrime(k));
            }
            nr += prime;
        }
        return nr;
    }
}

#ifndef TESTING
int main() {
    std::cout << "Solution : " << problem_035::solve(0) << std::endl;

    return 0;
}
#endif
