#include <vector>
#include <iostream>

namespace problem_034 {
    int factorial(int k) {
        int f = 1;
        for (int i = 1; i <= k; ++i) {
            f = f * i;
        }
        return f;
    }
    int solve(int n) {
        std::vector<int> fact;
        for (int i = 0; i <= 9; ++i) {
            fact.push_back(factorial(i));
        }

        int total = 0;
        for (int i = 10; i <= 1000000; ++i) {
            int k = i;
            int factSum = 0;
            while (k > 0) {
                factSum += fact[k % 10];
                k = k / 10;
            }
            if (i == factSum) {
                total += i;
            }
        }

        return total;
    }
}

#ifndef TESTING
int main() {
    std::cout << "Solution : " << problem_034::solve(0) << std::endl;

    return 0;
}
#endif
