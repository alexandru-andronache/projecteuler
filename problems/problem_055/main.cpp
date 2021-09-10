#include <vector>
#include <iostream>

namespace problem_055 {
    const int MAX_STEPS = 50;
    bool isPalindrom(const std::vector<int>& nr, int size) {
        int li = 0, ls = size - 1;
        while (li <= ls) {
            if (nr[li] != nr[ls]) {
                return false;
            }
            li++;
            ls--;
        }
        return true;
    }
    int solve() {
        int lychrel = 0;
        for (int k = 1; k <= 10000; ++k) {
            std::vector<int> nr(1000, 0);
            int n = k;
            int size = 0;
            while (n > 0) {
                nr[size] = n % 10;
                n = n / 10;
                size++;
            }
            int step = 0;
            do {
                std::vector<int> reverse = nr;
                std::reverse(std::begin(reverse), std::begin(reverse) + size);
                step++;
                int prev = 0;
                for (int i = 0; i < size; ++i) {
                    int total = nr[i] + reverse[i] + prev;
                    prev = total / 10;
                    nr[i] = total % 10;
                }
                while (prev > 0) {
                    nr[size] = prev % 10;
                    prev = prev / 10;
                    size++;
                }
            }
            while (step <= MAX_STEPS && !isPalindrom(nr, size));
            if (step > MAX_STEPS) {
                lychrel++;
            }
        }
        return lychrel;
    }
}

#ifndef TESTING
int main() {
    std::cout << "Solution : " << problem_055::solve(0) << std::endl;

    return 0;
}
#endif
