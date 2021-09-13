#include "big_number.h"
#include <vector>
#include <numeric>
#include <iostream>

namespace problem_056 {
    int solve() {
        size_t max = 0;
        for (int a = 2; a < 100; ++a) {
            big_number::BigNumber nr(1);
            for (int b = 1; b < 100; ++b) {
                nr *= a;
                max = std::max(max, nr.sumOfNumbers());
            }
        }

        return max;
    }
}

#ifndef TESTING
int main() {
    std::cout << "Solution : " << problem_056::solve(0) << std::endl;

    return 0;
}
#endif
