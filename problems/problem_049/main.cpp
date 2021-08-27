#include "sieve_eratosthenes.h"
#include <iostream>

namespace problem_049 {
    bool isPermutation(int i, int j) {
        std::string str = std::to_string(i);
        std::string str1 = std::to_string(i + j);
        std::string str2 = std::to_string(i + j + j);
        return (std::is_permutation(str.begin(), str.end(), str1.begin()) && std::is_permutation(str.begin(), str.end(), str2.begin()));
    }

    std::string solve() {
        const int N = 10000;
        math::SieveEratosthenes se(N);
        for (int i = 1000; i < N; ++i) {
            if (se.isPrime(i)) {
                for (int j = 1; j < N; ++j) {
                    if (i + 2 * j < N && isPermutation(i, j) && se.isPrime(i + j) && se.isPrime(i + j + j) && i != 1487) {
                        return std::to_string(i) + std::to_string(i + j) + std::to_string(i + j + j);
                    }
                }
            }
        }
        return "";
    }
}

#ifndef TESTING
int main() {
    std::cout << "Solution : " << problem_049::solve(0) << std::endl;

    return 0;
}
#endif
