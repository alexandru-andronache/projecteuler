#include <iostream>
#include <vector>
#include <numeric>
#include "sieve_eratosthenes.h"
#include "math_common.h"

namespace problem_060 {

    math::SieveEratosthenes sieve(100000000);

    int combine(int a, int b) {
        int times = 1;
        while (times <= b)
            times *= 10;
        return a * times + b;
    }

    bool isSol(const std::vector<int>& queue, const std::vector<int>& primes) {
        for (int i = 0; i < queue.size() - 1; ++i) {
            if (!sieve.isPrime(combine(primes[queue[i]], primes[queue.back()])) ||
                !sieve.isPrime(combine(primes[queue.back()], primes[queue[i]]))) {
                return false;
            }
        }
        return true;
    }

    int backtracking(const std::vector<int>& primes, int n) {
        int solMinim = std::numeric_limits<int>::max();

        std::vector<int> queue;
        int sum = 0;
        queue.push_back(-1);
        while (!queue.empty()) {
            if (queue.back() >= 0) {
                sum -= primes[queue.back()];
            }
            queue.back()++;
            sum += primes[queue.back()];
            if (sum < solMinim && queue.back() < primes.size() && isSol(queue, primes)) {
                if (queue.size() == n) {
                    solMinim = std::min(solMinim, sum);
                }
                else {
                    queue.push_back(queue.back());
                    sum += primes[queue.back()];
                }
            }
            else {
                while (!queue.empty() && queue.back() >= primes.size()) {
                    sum -= primes[queue.back()];
                    queue.pop_back();
                }
            }
        }

        return solMinim;
    }

    int solve(int n) {
        const int N = 10000;
        math::SieveEratosthenes se(N);
        std::vector<int> primes;

        for (int i = 3; i < N; ++i) {
            if (se.isPrime(i)) {
                primes.push_back(i);
            }
        }

        return backtracking(primes, n);
    }
}

#ifndef TESTING
int main() {
    std::cout << "Solution : " << problem_060::solve(5) << std::endl;

    return 0;
}
#endif
