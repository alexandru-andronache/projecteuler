#include <iostream>

namespace problem_003 {
    unsigned long long solve(unsigned long long n) {
        if (n % 2 == 0) {
            n = n / 2;
        }
        int k = 3;
        while (n > 1 && k < n) {
            if (n % k == 0) {
                n = n / k;
            }
            k += 2;
        }
        return k;
    }
}

#ifndef TESTING
int main() {
    std::cout << "Solution : " << problem_003::solve(600851475143) << std::endl;

    return 0;
}
#endif
