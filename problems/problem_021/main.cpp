#include "sieve_eratosthenes.h"
#include <iostream>

namespace problem_021 {
    int solve(int n) {
        int sol = 0;
        math::SieveEratosthenes se(n);
        for (int i = 2; i < n; ++i) {
            int sum = se.sumOfProperDivisors(i);
            if (se.sumOfProperDivisors(sum) == i && sum != i) {
                sol += i;
            }
        }

        return sol;
    }
}

#ifndef TESTING
int main() {
    std::cout << "Solution : " << problem_021::solve(0) << std::endl;

    return 0;
}
#endif
