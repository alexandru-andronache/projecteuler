#include "big_number.h"
#include <vector>
#include <iostream>

namespace problem_057 {
    int solve() {
        int sol = 0;
        big_number::BigNumber numerator(3);
        big_number::BigNumber denominator(2);
        for (int i = 2; i <= 1000; ++i) {
            numerator += denominator;
            std::swap(numerator, denominator);
            numerator += denominator;
            sol += numerator.size() > denominator.size();
        }
        return sol;
    }
}

#ifndef TESTING
int main() {
    std::cout << "Solution : " << problem_057::solve(0) << std::endl;

    return 0;
}
#endif
