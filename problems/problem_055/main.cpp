#include "big_number.h"
#include <vector>
#include <iostream>

namespace problem_055 {
    const int MAX_STEPS = 50;

    int solve() {
        int lychrel = 0;
        for (int k = 1; k <= 10000; ++k) {
            big_number::BigNumber nr(k);
            int step = 0;
            do {
                std::vector<int> reverse = nr.number;
                std::reverse(std::begin(reverse), std::end(reverse));
                step++;
                nr += reverse;
            }
            while (step <= MAX_STEPS && !nr.isPalindrom());
            if (step > MAX_STEPS) {
                lychrel++;
            }
        }
        return lychrel;
    }
}

#ifndef TESTING
int main() {
    std::cout << "Solution : " << problem_055::solve(0) << std::endl;

    return 0;
}
#endif
