#include <iostream>
#include <cmath>

namespace problem_069 {
    int solve(int n) {
        long long maxN = 1, maxPhi = 1; 
        for (int i = 2; i <= n; ++i) {
            long long p = i;
            long long total = 1;
            for (int j = 2; j <= std::sqrt(i); ++j) {
                int k = 0;
                while (p % j == 0) {
                    k++;
                    p = p / j;
                }
                if (k > 0) {
                    total *= std::pow(j, k - 1) * (j - 1);
                }
            }
            if (p > 1) {
                total *= (p - 1);
            }
            if (i * maxPhi > maxN * total) {
                maxN = i;
                maxPhi = total;
            }
        }

        return maxN;
    }
}

#ifndef TESTING
int main() {
    std::cout << "Solution : " << problem_069::solve(0) << std::endl;

    return 0;
}
#endif
