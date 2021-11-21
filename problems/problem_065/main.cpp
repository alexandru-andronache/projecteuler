#include "big_number.h"
#include <iostream>
#include <vector>

namespace problem_065 {
    int solve(int n) {
        std::vector<int> convergent{2, 1, 2};
        int k = 4;
        while (convergent.size() < n) {
            convergent.push_back(1);
            convergent.push_back(1);
            convergent.push_back(k);
            k = k + 2;
        }

        n--;
        big_number::BigNumber numerator(1);
        big_number::BigNumber denominator(convergent[n]);
        n--;

        while (n >= 0) {
            big_number::BigNumber temp(denominator);
            denominator = convergent[n] * denominator + numerator;
            numerator = temp;
            n--;
        }

        return denominator.sumOfNumbers();
    }
}

#ifndef TESTING
int main() {
    std::cout << "Solution : " << problem_065::solve(0) << std::endl;

    return 0;
}
#endif
