#include <iostream>

namespace problem_047 {
    bool nrOfPrimeFactors(int k, int n) {
        int i = 2;
        int nr = 0;
        while (k > 1) {
            if (k % i == 0) {
                nr++;
                while (k % i == 0) {
                    k = k / i;
                }
            }
            if (nr > n) {
                return false;
            }
            i++;
        }
        return nr == n;
    }

    int solve(int n) {
        int i = 2;
        while (true) {
            bool found = true;
            for (int j = 0; j < n; ++j) {
                if (!nrOfPrimeFactors(i + j, n)) {
                    found = false;
                }
            }
            if (found) {
                return i;
            }
            i++;
        }
        return 0;
    }
}

#ifndef TESTING
int main() {
    std::cout << "Solution : " << problem_047::solve(0) << std::endl;

    return 0;
}
#endif
