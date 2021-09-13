#include <vector>
#include <numeric>
#include <iostream>

namespace problem_056 {
    int solve() {
        const int LENGTH = 1000;
        int max = 0;
        for (int a = 2; a < 100; ++a) {
            std::vector<int> nr(LENGTH, 0);
            nr[0] = 1;
            for (int b = 1; b < 100; ++b) {
                int prev = 0;
                for (int i = 0; i < LENGTH; ++i) {
                    int k = nr[i] * a + prev;
                    nr[i] = k % 10;
                    prev = k / 10;
                }
                max = std::max(max, std::accumulate(nr.begin(), nr.end(), 0));
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
