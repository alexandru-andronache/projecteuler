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

TEST_F(SieveEratosthenesTest, sieve_eratosthenes_divisor_count) {
    SieveEratosthenes se(100);
    ASSERT_EQ(se.divisorCount(3), 2);
    ASSERT_EQ(se.divisorCount(15), 4);
    ASSERT_EQ(se.divisorCount(21), 4);
    ASSERT_EQ(se.divisorCount(28), 6);
}

TEST_F(SieveEratosthenesTest, sieve_eratosthenes_divisor_count_big_value) {
    SieveEratosthenes se(1000000);
    ASSERT_EQ(se.divisorCount(76576500), 576);
}

TEST_F(SieveEratosthenesTest, sieve_eratosthenes_sum_of_proper_divisors) {
    SieveEratosthenes se(1000);
    ASSERT_EQ(se.sumOfProperDivisors(220), 284);
    ASSERT_EQ(se.sumOfProperDivisors(284), 220);
}

TEST_F(SieveEratosthenesTest, sieve_eratosthenes_is_prime) {
    SieveEratosthenes se(1000);
    ASSERT_EQ(se.isPrime(100), false);
    ASSERT_EQ(se.isPrime(99), false);
    ASSERT_EQ(se.isPrime(23), true);
    ASSERT_EQ(se.isPrime(37), true);
}