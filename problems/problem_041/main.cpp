#include "math_common.h"
#include <vector>
#include <iostream>

namespace problem_041 {
    int solve() {
        for (int n = 9; n > 0; --n) {
            std::vector<int> numbers;
            for (int i = 1; i <= n; ++i) {
                numbers.push_back(i);
            }
            int max = 0;
            do {
                int k = 0;
                for (const auto& c : numbers) {
                    k = k * 10 + c;
                }
                if (math::isPrime(k)) {
                    max = std::max(max, k);
                }
            } while (std::next_permutation(numbers.begin(), numbers.end()));
            if (max > 0) {
                return max;
            }
        }
        return 0;
    }
}

#ifndef TESTING
int main() {
    std::cout << "Solution : " << problem_041::solve(0) << std::endl;

    return 0;
}
#endif
