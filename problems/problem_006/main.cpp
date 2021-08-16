#include <iostream>

namespace problem_006 {
    unsigned long long solve(int n) {
        return n * (n + 1) * (3 * n * n - n - 2) / 12;
    }
}

#ifndef TESTING
int main() {
    std::cout << "Solution : " << problem_006::solve(100) << std::endl;

    return 0;
}
#endif
