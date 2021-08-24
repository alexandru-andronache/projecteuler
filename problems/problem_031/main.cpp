#include <vector>
#include <numeric>
#include <iostream>

namespace problem_031 {
    std::vector<int> coins{1, 2, 5, 10, 20, 50, 100, 200};

    void calculate(int sum, int nrCoins, int& sol, int startValue) {
        if (nrCoins == 0) {
            sol++;
            return;
        }
        for (int i = startValue; i <= sum / coins[nrCoins]; ++i) {
            calculate(sum - i * coins[nrCoins], nrCoins - 1, sol, 0);
        }
    }

    int solve(int n) {

        std::vector<int> combinations;

        for (int i = 0; i < coins.size(); ++i) {
            int sol = 0;
            calculate(n, i, sol, 1);
            combinations.push_back(sol);
        }

        return std::accumulate(combinations.begin(), combinations.end(), 0);
    }
}

#ifndef TESTING
int main() {
    std::cout << "Solution : " << problem_031::solve(0) << std::endl;

    return 0;
}
#endif
