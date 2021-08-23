#include <cmath>
#include <vector>
#include <iostream>

namespace problem_029 {
    int solve(int n) {
        int total = (n - 1) * (n - 1);
        int duplicate = 0;
        std::vector<bool> checked(n + 1, true);
        for (int i = 2; i <= n; ++i) {
            std::vector<int> d(std::pow(n, 2), false);
            int k = 1;
            while (checked[i] && std::pow(i, k) <= n) {
                for (int j = 2; j <= n; ++j) {
                    if (d[j * k]) {
                        duplicate++;
                    }
                    d[j * k] = true;
                }
                k++;
                checked[std::pow(i, k)] = false;
            }
        }
        return total - duplicate;
    }
}

#ifndef TESTING
int main() {
    std::cout << "Solution : " << problem_029::solve(0) << std::endl;

    return 0;
}
#endif
