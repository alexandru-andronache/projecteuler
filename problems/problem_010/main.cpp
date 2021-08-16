#include <iostream>
#include "sieve_eratosthenes.h"

namespace problem_010 {
    unsigned long long solve(int n) {
        math::SieveEratosthenes se(n);
        return se.sumOfPrimes();
    }
}

#ifndef TESTING
int main() {
    std::cout << "Solution : " << problem_010::solve(2000000) << std::endl;

    return 0;
}
#endif
