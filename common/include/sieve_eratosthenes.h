#include <vector>

namespace math {
    class SieveEratosthenes {
    public:
        SieveEratosthenes(int size);

        /*
         * sum of the primes smaller then size
         */
        unsigned long long sumOfPrimes();

        /*
         * returns the n prime
         */
        int getPrime(int n);

    private:
        void calculate();
        std::vector<bool> sieve;
    };
}