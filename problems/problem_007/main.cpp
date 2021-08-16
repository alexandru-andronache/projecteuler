#include <iostream>
#include <vector>

namespace problem_007 {
    int solve(int n) {
        const int N = 1000000;
        std::vector<bool> prime(N, true);
        for (int i = 2; i < N; ++i) {
            if (prime[i]) {
                for (int j = i + i; j < N; j += i) {
                    prime[j] = false;
                }
            }
        }

        int k = 0;
        int index = 1;
        while (k < n && index < N) {
            index++;
            if (prime[index]) {
                k++;
            }
        }

        return index;
    }
}

#ifndef TESTING
int main() {
    std::cout << "Solution : " << problem_007::solve(0) << std::endl;

    return 0;
}
#endif
