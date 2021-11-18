#include <iostream>
#include <cmath>
#include <map>

namespace problem_064 {
    int solve(int n) {
        int sol = 0;

        for (int x = 2; x <= n; ++x) {
            int s = sqrt(x);
            if (s * s != x) {
                int a = 1;
                int b = -floor(sqrt(x));
                std::map<std::pair<int, int>, int> prevSteps;

                int steps = 0;
                while (prevSteps.count({a, b}) == 0) {
                    prevSteps.insert({{a, b}, steps});
                    int k = -b;
                    int l = (x - b * b) / a;

                    int nr = floor((sqrt(x) + k) / l);

                    a = l;
                    b = k - nr * l;
                    steps++;
                }

                if (steps % 2 == 1) {
                    sol++;
                }
            }
        }


        return sol;
    }
}

#ifndef TESTING
int main() {
    std::cout << "Solution : " << problem_064::solve(10000) << std::endl;

    return 0;
}
#endif
