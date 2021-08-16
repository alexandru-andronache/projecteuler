#include <iostream>
#include <numeric>

namespace problem_005 {
    unsigned long long solve(int n) {
        unsigned long long sol = 1;
        for (int i = 2; i <= n; ++i) {
            sol = std::lcm(sol, i);
        }

        return sol;
    }
}

#ifndef TESTING
int main() {
    std::cout << "Solution : " << problem_005::solve(20) << std::endl;

    return 0;
}
#endif
