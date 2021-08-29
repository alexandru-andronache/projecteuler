#include "sieve_eratosthenes.h"
#include <vector>
#include <cmath>
#include <iostream>

namespace problem_051 {
    int solve(int n) {
        const int N = 1000000;
        math::SieveEratosthenes se(N);
        for (int i = 100; i < N; ++i) {
            std::string nr = std::to_string(i);
            if (se.isPrime(i)) {
                for (int k = 1; k < std::pow(2, nr.size()); ++k) {
                    std::bitset<8> bits(k);
                    int count = 0;
                    std::string t = nr;
                    std::vector<int> primes;
                    for (int c = 0; c <= 9; ++c) {
                        for (int j = 0; j < bits.size(); ++j) {
                            if (bits.test(j)) {
                                t[j] = std::to_string(c)[0];
                            }
                        }
                        int number = std::stoi(t);
                        if (se.isPrime(number) && std::to_string(number).size() == t.size()) {
                            count += se.isPrime(std::stoi(t));
                            primes.push_back(std::stoi(t));
                        }
                        if (count == n) {
                            return primes[0];
                        }
                    }
                }
            }
        }
        return 0;
    }
}

#ifndef TESTING
int main() {
    std::cout << "Solution : " << problem_051::solve(0) << std::endl;

    return 0;
}
#endif
