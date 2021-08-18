#include <iostream>
#include <vector>
#include <numeric>

namespace problem_016 {
    int solve(int n) {
        const int N = 1000;
        std::vector<int> power(N, 0);
        power[0] = 1;
        for (int i = 1; i <= n; ++i) {
            int prev = 0;
            for (int j = 0; j < N; ++j) {
                power[j] = power[j] * 2 + prev;
                prev = power[j] / 10;
                power[j] = power[j] % 10;
            }
        }

        return std::accumulate(power.begin(), power.end(), 0);
    }
}

#ifndef TESTING
int main() {
    std::cout << "Solution : " << problem_016::solve(0) << std::endl;

    return 0;
}
#endif
