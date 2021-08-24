#include <iostream>

namespace problem_038 {
    int solve() {
        int max = 0;
        for (int i = 10; i < 10000; ++i) {
            std::string str;
            int n = 1;
            while (str.size() < 9) {
                str += std::to_string(i * n);
                n++;
            }
            if (str.size() == 9) {
                bool valid = true;
                for (char j = '1'; j <= '9'; ++j) {
                    valid = valid && (std::count(str.begin(), str.end(), j) == 1);
                }
                max = std::max(max, std::stoi(str) * valid);
            }
        }
        return max;
    }
}

#ifndef TESTING
int main() {
    std::cout << "Solution : " << problem_038::solve(0) << std::endl;

    return 0;
}
#endif
