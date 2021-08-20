#include <vector>
#include <iostream>

namespace problem_025 {
    int solve(int n) {
        std::vector<int> fib1(2 * n, 0);
        std::vector<int> fib2(2 * n, 0);
        std::vector<int> sum(2 * n, 0);
        fib1[0] = 1;
        fib2[0] = 1;
        int index = 2;
        int nrDigits = 1;
        while (nrDigits < n) {
            int prev = 0;
            for (int i = 0; i < sum.size(); ++i) {
                sum[i] = fib1[i] + fib2[i] + prev;
                prev = sum[i] / 10;
                sum[i] = sum[i] % 10;
                if (sum[i] > 0) {
                    nrDigits = i + 1;
                }
            }
            fib1 = fib2;
            fib2 = sum;
            sum = std::vector<int>(2 * n, 0);
            index++;
        }
        return index;
    }
}

#ifndef TESTING
int main() {
    std::cout << "Solution : " << problem_025::solve(1000) << std::endl;

    return 0;
}
#endif
