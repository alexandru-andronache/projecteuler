#include "MathTest.h"
#include "math_common.h"

using namespace math;

TEST_F(MathTest, is_prime) {
    ASSERT_EQ(isPrime(75), false);
    ASSERT_EQ(isPrime(33), false);
    ASSERT_EQ(isPrime(37), true);
    ASSERT_EQ(isPrime(41), true);
}

TEST_F(MathTest, EulersTotient) {
    ASSERT_EQ(EulersTotient(999005), 608256);
    ASSERT_EQ(EulersTotient(123456), 41088);
}
