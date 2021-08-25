#include <vector>
#include <iostream>

namespace problem_043 {
    bool isDivisible(const std::vector<int>& numbers, int start, int divisible) {
        return ((numbers[start] * 100 + numbers[start + 1] * 10 + numbers[start + 2]) % divisible == 0);
    }
    unsigned long long solve() {
        std::vector<int> numbers{1, 0, 2, 3, 4, 5, 6, 7, 8, 9};
        unsigned long long sum = 0;
        do {
            if (isDivisible(numbers, 1, 2) &&
                isDivisible(numbers, 2, 3) &&
                isDivisible(numbers, 3, 5) &&
                isDivisible(numbers, 4, 7) &&
                isDivisible(numbers, 5, 11) &&
                isDivisible(numbers, 6, 13) &&
                isDivisible(numbers, 7, 17)) {
                unsigned long long nr = 0;
                for (const auto& n : numbers) {
                    nr = nr * 10 + n;
                }
                sum += nr;
            }
        } while (std::next_permutation(numbers.begin(), numbers.end()));

        return sum;
    }
}

#ifndef TESTING
int main() {
    std::cout << "Solution : " << problem_043::solve(0) << std::endl;

    return 0;
}
#endif
