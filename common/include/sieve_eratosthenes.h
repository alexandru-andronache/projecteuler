#include <vector>

namespace math {
    class SieveEratosthenes {
    public:
        explicit SieveEratosthenes(int size);

        /*
         * sum of the primes smaller then size
         */
        unsigned long long sumOfPrimes();

        /*
         * returns the n prime
         */
        int getPrime(int n);

        /*
         * returns the number of divisors of n
         */
        int divisorCount(int n);

        /*
         * returns the sum of the proper divisors
         */
        int sumOfProperDivisors(int n);

    private:
        void calculate();
        std::vector<bool> sieve;
    };
}