#include <iostream>
#include <vector>

namespace problem_015 {
    unsigned long long solve(int n) {
        std::vector<std::vector<unsigned long long>> routes(n + 1, std::vector<unsigned long long>(n + 1, 0));
        routes[0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            routes[0][i] = routes[0][i - 1];
        }
        for (int i = 1; i <= n; ++i) {
            routes[i][0] = routes[i - 1][0];
            for (int j = 1; j <= n; ++j) {
                routes[i][j] = routes[i - 1][j] + routes[i][j - 1];
            }
        }
        return routes[n][n];
    }
}

#ifndef TESTING
int main() {
    std::cout << "Solution : " << problem_015::solve(0) << std::endl;

    return 0;
}
#endif
