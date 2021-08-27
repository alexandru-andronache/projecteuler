#include <iostream>

namespace problem_048 {
    std::string solve(int n) {
        std::string sum = "0000000000";
        for (int i = 1; i <= n; ++i) {
            std::string prod = "1000000000";
            for (int l = 1; l <= i; ++l) {
                int p = 0;
                for (int j = 0; j < prod.size(); ++j) {
                    int k = (prod[j] - '0') * i + p;
                    prod[j] = std::to_string(k % 10)[0];
                    p = k / 10;
                }
            }
            int p = 0;
            for (int j = 0; j < prod.size(); ++j) {
                int k = sum[j] - '0' + prod[j] - '0' + p;
                sum[j] = std::to_string(k % 10)[0];
                p = k / 10;
            }
        }
        std::reverse(sum.begin(), sum.end());
        return sum;
    }
}

#ifndef TESTING
int main() {
    std::cout << "Solution : " << problem_048::solve(0) << std::endl;

    return 0;
}
#endif
