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
        if (queue.size() <= 1) {
            return true;
        }
        for (int i = 0; i < queue.size() - 1; ++i) {
            if (queue[i] == queue.back()) {
                return false;
            }
        }
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
        int sums = 0;
        queue.push_back(-1);
        while (!queue.empty()) {
            if (queue.back() >= 0) {
                sums -= primes[queue.back()];
            }
            queue.back()++;
            sums += primes[queue.back()];
            if (sums < solMinim && queue.back() < primes.size() && isSol(queue, primes)) {
                if (queue.size() == n) {
                    solMinim = std::min(solMinim, sums);
                }
                else {
                    queue.push_back(-1);
                }
            }
            else {
                while (!queue.empty() && queue.back() >= primes.size()) {
                    sums -= primes[queue.back()];
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

        for (int i = 2; i < N; ++i) {
            if (se.isPrime(i)) {
                primes.push_back(i);
            }
        }


        return backtracking(primes, n);
    }
}

#ifndef TESTING
int main() {
    std::cout << "Solution : " << problem_060::solve(0) << std::endl;

    return 0;
}
#endif
