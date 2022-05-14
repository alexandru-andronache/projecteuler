#include <iostream>
#include <vector>

namespace problem_068 {
    unsigned long long solve() {
        std::vector<int> numbers{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        unsigned long long sol = 0;

        do {
            bool valid = true;
            for (int i = 1; i <= 9; i += 2) {
                valid = valid && (numbers[i] != 10);
            }

            int sum = numbers[0] + numbers[1] + numbers[3];
            for (int i = 2; i <= 8; i += 2) {
                valid = valid && (sum == numbers[i] + numbers[i + 1] + numbers[(i + 3) % 10]);
            }

            if (valid) {
                std::vector<int> magic;
                for (int i = 0; i <= 8; i += 2) {
                    if (numbers[i] == std::min({numbers[0], numbers[2], numbers[4], numbers[6], numbers[8]})) {
                        for (int j = 0; j < 5; ++j) {
                            magic.push_back(numbers[(i + j * 2) % 10]);
                            magic.push_back(numbers[(i + j * 2 + 1) % 10]);
                            magic.push_back(numbers[(i + j * 2 + 3) % 10]);
                        }
                    }
                }
                unsigned long long val = 0;
                for (const auto &nr : magic) {
                    if (nr >= 10) {
                        val = val * 100 + nr;
                    }
                    else {
                        val = val * 10 + nr;
                    }
                }
                sol = std::max(sol, val);
            }
        } while (std::next_permutation(numbers.begin(), numbers.end()));

        return sol;
    }
}

#ifndef TESTING
int main() {
    std::cout << "Solution : " << problem_068::solve() << std::endl;

    return 0;
}
#endif
