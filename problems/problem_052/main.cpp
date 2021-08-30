#include <iostream>

namespace problem_052 {
    int solve() {
        int n = 10;
        while (true) {
            if (std::to_string(n * 6).size() == std::to_string(n).size()) {
                std::string p = std::to_string(n);
                int count = 0;
                for (int i = 2; i <= 6; ++i) {
                    std::string str = std::to_string(n * i);
                    count += std::is_permutation(str.begin(), str.end(), p.begin());
                }
                if (count == 6 - 2 + 1) {
                    return n;
                }
            }
            n++;
        }
        return 0;
    }
}

#ifndef TESTING
int main() {
    std::cout << "Solution : " << problem_052::solve(0) << std::endl;

    return 0;
}
#endif
