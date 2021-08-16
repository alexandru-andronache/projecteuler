#include "SieveEratosthenesTest.h"
#include "sieve_eratosthenes.h"

using namespace math;

TEST_F(SieveEratosthenesTest, sieve_eratosthenes_sum_of_first_primes) {
    SieveEratosthenes se(10);
    ASSERT_EQ(se.sumOfPrimes(), 17);
}

TEST_F(SieveEratosthenesTest, sieve_eratosthenes_sum_of_first_primes_big_value) {
    SieveEratosthenes se(2000000);
    ASSERT_EQ(se.sumOfPrimes(), 142913828922);
}

TEST_F(SieveEratosthenesTest, sieve_eratosthenes_get_prime) {
    SieveEratosthenes se(100);
    ASSERT_EQ(se.getPrime(6), 13);
}

TEST_F(SieveEratosthenesTest, sieve_eratosthenes_get_prime_big_value) {
    SieveEratosthenes se(1000000);
    ASSERT_EQ(se.getPrime(10001), 104743);
}