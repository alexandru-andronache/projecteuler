#include <cmath>
#include <iostream>

namespace problem_045 {
    bool isPentagonNumber(unsigned long long k) {
        unsigned long long delta = 1 + 24 * k;
        unsigned long long s = std::sqrt(delta);
        if (s * s == delta) {
            if ((1 + s) % 6 == 0) {
                return true;
            }
        }
        return false;
    }

    bool isTriangleNumber(unsigned long long k) {
        unsigned long long delta = 1 + 8 * k;
        unsigned long long s = std::sqrt(delta);
        if (s * s == delta) {
            if ((1 + s) % 2 == 0) {
                return true;
            }
        }
        return false;
    }

    unsigned long long solve() {
        int i = 144;
        while (true) {
            unsigned long long h = i * (2 * i - 1);
            if (isPentagonNumber(h) && isTriangleNumber(h)) {
                return h;
            }
            i++;
        }
        return 0;
    }
}

#ifndef TESTING
int main() {
    std::cout << "Solution : " << problem_045::solve(0) << std::endl;

    return 0;
}
#endif
