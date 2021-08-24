#include <vector>
#include <cmath>
#include <iostream>

namespace problem_030 {
    int solve(int n) {
        int sum = 0;
        std::vector<int> numbers;
        for (int i = 0; i <= 9; ++i) {
            numbers.push_back(std::pow(i, n));
        }
        for (int i = 10; i <= 1000000; ++i) {
            int k = i;
            int s = 0;
            while (k > 0) {
                s += numbers[k % 10];
                k = k / 10;
            }
            if (s == i) {
                sum += i;
            }
        }
        return sum;
    }
}

#ifndef TESTING
int main() {
    std::cout << "Solution : " << problem_030::solve(0) << std::endl;

    return 0;
}
#endif
