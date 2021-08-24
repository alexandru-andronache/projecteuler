#include <iostream>

namespace problem_039 {
    int solve(int n) {
        int nr = 0;
        int max = 0;
        for (int sum = 3; sum <= n; ++sum) {
            int comb = 0;
            for (int i = 1; i < sum; ++i) {
                for (int j = 1; j < sum - i; ++j) {
                    int k = sum - i - j;
                    int p = std::max({i, j, k});
                    if (p * p == i * i + j * j || p * p == i * i + k * k || p * p == j * j + k * k) {
                        comb++;
                    }
                }
            }
            if (comb > max) {
                max = comb;
                nr = sum;
            }
        }
        return nr;
    }
}

#ifndef TESTING
int main() {
    std::cout << "Solution : " << problem_039::solve(1000) << std::endl;

    return 0;
}
#endif
