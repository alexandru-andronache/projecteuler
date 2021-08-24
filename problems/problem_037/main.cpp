#include "sieve_eratosthenes.h"
#include <iostream>

namespace problem_037 {
    bool isTruncatablePrimeLeft(int k, const math::SieveEratosthenes& se) {
        while (k > 0) {
            if (!se.isPrime(k)) {
                return false;
            }
            k = k / 10;
        }
        return true;
    }

    bool isTruncatablePrimeRight(int k, const math::SieveEratosthenes& se) {
        int m = 10;
        while (m < k) {
            if (!se.isPrime(k % m)) {
                return false;
            }
            m = m * 10;
        }
        return true;
    }

    int solve() {
        int sum = 0;
        int nr = 0;
        int k = 10;
        math::SieveEratosthenes se(10000000);
        while (nr < 11) {
            if (isTruncatablePrimeLeft(k, se) && isTruncatablePrimeRight(k, se)) {
                nr++;
                sum += k;
            }
            k++;
        }
        return sum;
    }
}

#ifndef TESTING
int main() {
    std::cout << "Solution : " << problem_037::solve() << std::endl;

    return 0;
}
#endif
