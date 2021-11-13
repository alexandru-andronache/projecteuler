#include "big_number.h"
#include <iostream>

namespace problem_063 {
    int solve() {
        int sol = 0;
        for (int i = 1; i < 10; ++i) {
            big_number::BigNumber power(1);
            for (int j = 1; j < 30; ++j) {
                power *= i;

                if (power.size() == j) {
                    sol++;
                }
            }
        }

        return sol;
    }
}

#ifndef TESTING
int main() {
    std::cout << "Solution : " << problem_063::solve() << std::endl;

    return 0;
}
#endif
