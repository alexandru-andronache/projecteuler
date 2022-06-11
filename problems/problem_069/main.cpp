#include "fraction.h"
#include "math_common.h"
#include <iostream>
#include <cmath>

namespace problem_069 {
    int solve(int n) {
        fraction::Fraction f(1, 1);
        for (int i = 2; i <= n; ++i) {
            f = std::max(f, fraction::Fraction(i, math::EulersTotient(i)));
        }

        return f.getNumerator();
    }
}

#ifndef TESTING
int main() {
    std::cout << "Solution : " << problem_069::solve(1000000) << std::endl;

    return 0;
}
#endif
