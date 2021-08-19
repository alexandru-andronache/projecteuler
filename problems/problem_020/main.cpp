#include <vector>
#include <numeric>
#include <iostream>

namespace problem_020 {
    int solve(int n) {
        std::vector<int> numbers(10000, 0);
        numbers[0] = 1;
        for (int k = 2; k <= n; ++k) {
            int prev = 0;
            for (int i = 0; i < numbers.size(); ++i) {
                numbers[i] = numbers[i] * k + prev;
                prev = numbers[i] / 10;
                numbers[i] = numbers[i] % 10;
            }
        }
        return std::accumulate(numbers.begin(), numbers.end(), 0);
    }
}

#ifndef TESTING
int main() {
    std::cout << "Solution : " << problem_020::solve(0) << std::endl;

    return 0;
}
#endif
