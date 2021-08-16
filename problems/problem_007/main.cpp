#include <iostream>
#include <vector>
#include "sieve_eratosthenes.h"

namespace problem_007 {
    int solve(int n) {
        math::SieveEratosthenes se(1000000);
        return se.getPrime(n);
    }
}

#ifndef TESTING
int main() {
    std::cout << "Solution : " << problem_007::solve(10001) << std::endl;

    return 0;
}
#endif
