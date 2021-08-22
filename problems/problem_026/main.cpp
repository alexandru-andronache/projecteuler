#include <vector>
#include <iostream>

namespace problem_026 {
    int solve(int n) {
        int maxSize = 0;
        int number = 0;

        for (int i = 2; i < n; ++i) {
            std::vector<int> rest(i, 0);
            int p = 1;
            int nr = 0;
            while (p > 0 && rest[p] == 0) {
                nr++;
                rest[p] = nr;
                p = (p * 10) % i;
            }
            if (p > 0 && (nr - rest[p] + 1 > maxSize)) {
                maxSize = nr - rest[p] + 1;
                number = i;
            }
        }

        return number;
    }
}

#ifndef TESTING
int main() {
    std::cout << "Solution : " << problem_026::solve(1000) << std::endl;

    return 0;
}
#endif
