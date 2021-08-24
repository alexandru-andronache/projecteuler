#include <vector>
#include <numeric>
#include <iostream>

namespace problem_031 {
    std::vector<int> coins{1, 2, 5, 10, 20, 50, 100, 200};

    int calculate(int sum, int nrCoins, int startValue) {
        if (nrCoins == 0) {
            return 1;
        }
        int total = 0;
        for (int i = startValue; i <= sum / coins[nrCoins]; ++i) {
            total += calculate(sum - i * coins[nrCoins], nrCoins - 1, 0);
        }
        return total;
    }

    int solve(int n) {
        std::vector<int> combinations;
        for (int i = 0; i < coins.size(); ++i) {
            combinations.push_back(calculate(n, i, 1));
        }

        return std::accumulate(combinations.begin(), combinations.end(), 0);
    }
}

#ifndef TESTING
int main() {
    std::cout << "Solution : " << problem_031::solve(200) << std::endl;

    return 0;
}
#endif
