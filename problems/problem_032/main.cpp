#include <vector>
#include <set>
#include <numeric>
#include <iostream>

namespace problem_032 {
    int isSolution(const std::vector<int>& numbers, int size1, int size2) {
        int nr1 = 0, nr2 = 0, prod = 0;
        for (int i = 0; i < size1; ++i) {
            nr1 = nr1 * 10 + numbers[i];
        }
        for (int i = size1; i < size1 + size2; ++i) {
            nr2 = nr2 * 10 + numbers[i];
        }
        for (int i = size1 + size2; i < numbers.size(); ++i) {
            prod = prod * 10 + numbers[i];
        }
        if (nr1 * nr2 == prod) {
            return prod;
        }
        return 0;
    }

    int solve() {
        std::vector<int> numbers {1, 2, 3, 4, 5, 6, 7, 8, 9};
        std::set<int> sol;

        do {
            sol.insert(isSolution(numbers, 1, 4));
            sol.insert(isSolution(numbers, 2, 3));
            sol.insert(isSolution(numbers, 3, 2));
            sol.insert(isSolution(numbers, 4, 1));
        } while(std::next_permutation(numbers.begin(), numbers.end()));

        return std::accumulate(sol.begin(), sol.end(), 0);
    }
}

#ifndef TESTING
int main() {
    std::cout << "Solution : " << problem_032::solve() << std::endl;

    return 0;
}
#endif
