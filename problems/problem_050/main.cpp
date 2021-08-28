#include "sieve_eratosthenes.h"
#include <vector>
#include <iostream>

namespace problem_050 {
    int solve(int n) {
        math::SieveEratosthenes se(n + 1);
        std::vector<int> primes;
        for (int i = 2; i < n + 1; ++i) {
            if (se.isPrime(i)) {
                primes.push_back(i);
            }
        }
        std::vector<int> sums;
        sums.push_back(0);
        int i = 1;
        while (sums[i - 1] + primes[i - 1] <= n) {
            sums.push_back(sums[i - 1] + primes[i - 1]);
            i++;
        }

        int nr = sums.size() - 1;
        while (nr > 0) {
            for (int i = 0; i < sums.size() - nr; ++i) {
                if (se.isPrime(sums[i + nr] - sums[i])) {
                    return sums[i + nr] - sums[i];
                }
            }
            nr--;
        }

        return 0;
    }
}

#ifndef TESTING
int main() {
    std::cout << "Solution : " << problem_050::solve(1000000) << std::endl;

    return 0;
}
#endif
