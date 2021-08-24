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
}