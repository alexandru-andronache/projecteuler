#include <iostream>
#include <vector>

namespace problem_017 {
    int solve(int n) {
        size_t sum = 0;
        std::vector<std::string> numbers {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
        std::vector<std::string> numbersTeen {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
        std::vector<std::string> teens{"twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
        std::string hundred = "hundred";
        std::string thousand = "thousand";
        std::string andLiteral = "and";

        for (int i = 1; i <= std::min(n, 9); ++i) {
            sum += numbers[i].size();
        }
        for (int i = 10; i <= std::min(n, 19); ++i) {
            sum += numbersTeen[i - 10].size();
        }
        for (int i = 20; i <= std::min(n, 99); i += 10) {
            sum += teens[(i - 20) / 10].size();
            for (int j = i + 1; j <= std::min(n, i + 9); ++j) {
                sum += teens[(i - 20) / 10].size() + numbers[j - i].size();
            }
        }

        for (int k = 100; k <= std::min(n, 999); k += 100) {
            sum += numbers[k / 100].size() + hundred.size();
            for (int i = k + 1; i <= std::min(n, k + 9); ++i) {
                sum += numbers[k / 100].size() + hundred.size() + andLiteral.size() + numbers[i - k].size();
            }
            for (int i = k + 10; i <= std::min(n, k + 19); ++i) {
                sum += numbers[k / 100].size() + hundred.size() + andLiteral.size() + numbersTeen[i - k - 10].size();
            }
            for (int i = k + 20; i <= std::min(n, k + 99); i += 10) {
                sum += numbers[k / 100].size() + hundred.size() + andLiteral.size() + teens[(i - k - 20) / 10].size();
                for (int j = 1 + i; j <= std::min(n, i + 9); ++j) {
                    sum += numbers[k / 100].size() + hundred.size() + andLiteral.size() + teens[(i - k - 20) / 10].size() + numbers[j - i].size();
                }
            }
        }

        if (n >= 1000) {
            sum += numbers[1].size() + thousand.size();
        }

        return sum;
    }
}

#ifndef TESTING
int main() {
    std::cout << "Solution : " << problem_017::solve(0) << std::endl;

    return 0;
}
#endif
