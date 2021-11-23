#include "big_number.h"
#include <iostream>
#include <cmath>

namespace problem_066 {
    bool test(const big_number::BigNumber& x, int d, const big_number::BigNumber& y) {
        return (x * x == d * y * y + 1);
    }

    int solve(int n) {

        big_number::BigNumber maxX(0);
        int maxD = 0;

        for (int d = 2; d <= n; ++d) {
            int s = sqrt(d);
            if (s * s != d) {
                long long a = 1;
                long long b = -floor(sqrt(d));
                big_number::BigNumber x(floor(sqrt(d)));
                big_number::BigNumber y(1);
                big_number::BigNumber prevX(1);
                big_number::BigNumber prevY(0);

                while (!test(x, d, y)) {
                    long long k = -b;
                    long long l = (d - b * b) / a;

                    long long nr = floor((sqrt(d) + k) / l);
                    big_number::BigNumber tempX = x, tempY = y;
                    x = nr * x + prevX;
                    y = nr * y + prevY;
                    prevX = tempX;
                    prevY = tempY;

                    a = l;
                    b = k - nr * l;
                }

                if (maxX < x) {
                    maxX = x;
                    maxD = d;
                }
            }
        }

        return maxD;
    }
}

#ifndef TESTING
int main() {
    std::cout << "Solution : " << problem_066::solve(1000) << std::endl;

    return 0;
}
#endif
