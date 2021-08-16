#include <iostream>

namespace problem_002 {
    unsigned long long solve(int n) {
        unsigned long long sum = 0;
        int fib1 = 1;
        int fib2 = 2;
        while (fib2 < n) {
            if (fib2 % 2 == 0) {
                sum += fib2;
            }
            int t = fib1 + fib2;
            fib1 = fib2;
            fib2 = t;
        }

        return sum;
    }
}

#ifndef TESTING
int main() {
    std::cout << "Solution : " << problem_002::solve(4000000) << std::endl;

    return 0;
}
#endif
