#include <iostream>
#include <vector>

namespace problem_014 {
    int solve(int n) {
        std::vector<int> results(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            unsigned long long nr = i;
            int size = 1;
            while (nr > 1) {
                if (nr < n && results[nr] > 0) {
                    size += results[nr] - 1;
                    nr = 1;
                }
                else {
                    size++;
                    if (nr % 2) {
                        nr = 3 * nr + 1;
                    }
                    else {
                        nr = nr / 2;
                    }
                }
            }

            results[i] = size;
        }

        return std::max_element(results.begin(), results.end()) - results.begin();
    }
}

#ifndef TESTING
int main() {
    std::cout << "Solution : " << problem_014::solve(1000000) << std::endl;

    return 0;
}
#endif
