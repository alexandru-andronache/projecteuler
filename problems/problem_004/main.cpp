#include <iostream>

namespace problem_004 {
    int reverseNumber(int nr) {
        int s = 0;
        while (nr > 0) {
            s = s * 10 + nr % 10;
            nr = nr / 10;
        }
        return s;
    }

    bool isPalindrom(int nr) {
        return nr == reverseNumber(nr);
    }

    unsigned long long solve(int min, int max) {
        int sol = 0;
        for (int i = min; i <= max; ++i) {
            for (int j = min; j <= max; ++j) {
                if (isPalindrom(i * j)) {
                    sol = std::max(sol, i * j);
                }
            }
        }
        return sol;
    }
}

#ifndef TESTING
int main() {
    std::cout << "Solution : " << problem_004::solve(100, 999) << std::endl;

    return 0;
}
#endif
