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

        for (int k = 0; k <= std::min(n, 999); k += 100) {
            int factor = (k > 0);
            sum += numbers[k / 100].size() + hundred.size() * factor;
            for (int i = k + 1; i <= std::min(n, k + 9); ++i) {
                sum += numbers[k / 100].size() + (hundred.size() + andLiteral.size()) * factor + numbers[i - k].size();
            }
            for (int i = k + 10; i <= std::min(n, k + 19); ++i) {
                sum += numbers[k / 100].size() + (hundred.size() + andLiteral.size()) * factor + numbersTeen[i - k - 10].size();
            }
            for (int i = k + 20; i <= std::min(n, k + 99); i += 10) {
                sum += numbers[k / 100].size() + (hundred.size() + andLiteral.size()) * factor + teens[(i - k - 20) / 10].size();
                for (int j = 1 + i; j <= std::min(n, i + 9); ++j) {
                    sum += numbers[k / 100].size() + (hundred.size() + andLiteral.size()) * factor + teens[(i - k - 20) / 10].size() + numbers[j - i].size();
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
