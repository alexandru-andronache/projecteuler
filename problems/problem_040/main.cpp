#include <vector>
#include <iostream>

namespace problem_040 {
    int solve() {
        std::vector<int> d {1, 10, 100, 1000, 10000, 100000, 1000000};
        int i = 1;
        int prod = 1;
        int size = 0;
        auto it = d.begin();
        while (size < d.back()) {
            std::string str = std::to_string(i);
            std::reverse(str.begin(), str.end());
            size += str.length();
            if (size >= *it) {
                prod *= str[size - *it] - '0';
                it++;
            }
            i++;
        }

        return prod;
    }
}

#ifndef TESTING
int main() {
    std::cout << "Solution : " << problem_040::solve() << std::endl;

    return 0;
}
#endif
