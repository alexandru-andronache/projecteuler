#include "sieve_eratosthenes.h"
#include <numeric>

namespace math {
    SieveEratosthenes::SieveEratosthenes(int size) {
        sieve = std::vector<bool>(size, true);
        calculate();
    }

    void SieveEratosthenes::calculate() {
        sieve[0] = sieve[1] = false;
        for (int i = 2; i < sieve.size(); ++i) {
            if (sieve[i]) {
                for (int j = i + i; j < sieve.size(); j += i) {
                    sieve[j] = false;
                }
            }
        }
    }

    unsigned long long SieveEratosthenes::sumOfPrimes() {
        unsigned long long sum = 0;
        for (int i = 2; i < sieve.size(); ++i) {
            sum += i * sieve[i];
        }
        return sum;
    }

    int SieveEratosthenes::getPrime(int n) {
        int k = 0;
        int index = 1;
        while (k < n && index < sieve.size()) {
            index++;
            if (sieve[index]) {
                k++;
            }
        }

        return index;
    }

    int SieveEratosthenes::divisorCount(int n) {
        int count = 1;
        for (int i = 2; i <= n; ++i) {
            int p = 0;
            while (sieve[i] && n % i == 0) {
                n = n / i;
                p++;
            }
            count *= p + 1;
        }
        return count;
    }

    int SieveEratosthenes::sumOfProperDivisors(int n) {
        int prod = 1;
        int originalNumber = n;
        for (int i = 2; i <= n; ++i) {
            int p = 0;
            while (sieve[i] && n % i == 0) {
                n = n / i;
                p++;
            }
            prod *= (std::pow(i, p + 1) - 1) / (i - 1);
        }
        return prod - originalNumber;
    }

    bool SieveEratosthenes::isPrime(int n) {
        if (n <= 0 || n >= sieve.size()) {
            return false;
        }
        return sieve[n];
    }
}