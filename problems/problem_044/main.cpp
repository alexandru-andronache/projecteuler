#include <vector>
#include <cmath>
#include <iostream>

namespace problem_044 {
    bool isPentagonNumber(int k) {
        int delta = 1 + 24 * k;
        int s = std::sqrt(delta);
        if (s * s == delta) {
            if ((1 + s) % 6 == 0) {
                return true;
            }
        }
        return false;
    }

    int solve() {
        const int N = 3000;
        int min = std::numeric_limits<int>::max();
        std::vector<int> pentagonNumbers;
        for (int i = 1; i <= N; ++i) {
            pentagonNumbers.push_back(i * (3 * i - 1) / 2);
        }

        for (int i = 0; i < pentagonNumbers.size(); ++i) {
            for (int j = i + 1; j < pentagonNumbers.size(); ++j) {
                if (isPentagonNumber(pentagonNumbers[i] + pentagonNumbers[j]) &&
                    isPentagonNumber(pentagonNumbers[j] - pentagonNumbers[i])) {
                    min = std::min(min, pentagonNumbers[j] - pentagonNumbers[i]);
                }
            }
        }

        return min;
    }
}

#ifndef TESTING
int main() {
    std::cout << "Solution : " << problem_044::solve(0) << std::endl;

    return 0;
}
#endif
