#include <cmath>

namespace math {
    bool isPrime(unsigned long long n) {
        for (int i = 2; i <= std::sqrt(n); ++i) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }

    long long EulersTotient(unsigned long long n) {
        long long total = 1;
        long long p = n;
        for (int i = 2; i <= std::sqrt(n); ++i) {
            int k = 0;
            while (p % i == 0) {
                k++;
                p = p / i;
            }
            if (k > 0) {
                total *= std::pow(i, k - 1) * (i - 1);
            }
        }
        if (p > 1) {
            total *= (p - 1);
        }
        return total;
    }
}