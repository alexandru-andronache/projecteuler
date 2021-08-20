#include <vector>
#include <iostream>

namespace problem_024 {
    unsigned long long factorial(int n) {
        int p = 1;
        for (int i = 1; i <= n; ++i) {
            p = p * i;
        }
        return p;
    }
    std::string solve(int n, int size) {
        std::vector<int> numbers;
        for (int i = 0; i <= size; ++i) {
            numbers.push_back(i);
        }
        std::string sol;
        while (n > 1) {
            int p = factorial(numbers.size() - 1);
            int k = (n - 1) / p;
            sol += std::to_string(numbers[k]);
            numbers.erase(numbers.begin() + k);
            n = n - k * p;
        }
        for (const auto& nr : numbers) {
            sol += std::to_string(nr);
        }

        return sol;
    }
}

#ifndef TESTING
int main() {
    std::cout << "Solution : " << problem_024::solve(1000000, 9) << std::endl;

    return 0;
}
#endif
