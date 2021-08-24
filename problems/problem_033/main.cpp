#include <iostream>

namespace problem_033 {
    void simplify(int& n, int& d) {
        int k = 2;
        while (k < 1000) {
            while (n % k == 00 &&  d % k == 0) {
                n = n / k;
                d = d / k;
            }
            k++;
        }
    }

    int solve() {
        int numerator = 1;
        int denominator = 1;
        for (int i = 10; i <= 99; ++i) {
            for (int j = 10; j < i; ++j) {
                if ((j % 10 == i % 10 && j % 10 != 0 && j * (i / 10) == i * (j / 10)) ||
                    (j % 10 == i / 10 && j % 10 != 0 && j * (i % 10) == i * (j / 10)) ||
                    (j / 10 == i % 10 && j / 10 != 0 && j * (i / 10) == i * (j % 10)) ||
                    (j / 10 == i / 10 && j / 10 != 0 && j * (i % 10) == i * (j % 10))) {
                    numerator = numerator * j;
                    denominator = denominator * i;
                }
            }
        }
        simplify(numerator, denominator);

        return denominator;
    }
}

#ifndef TESTING
int main() {
    std::cout << "Solution : " << problem_033::solve() << std::endl;

    return 0;
}
#endif
