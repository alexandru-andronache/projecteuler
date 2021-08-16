#include "MathTest.h"
#include "math_common.h"

using namespace math;

TEST_F(MathTest, is_prime) {
    ASSERT_EQ(isPrime(75), false);
    ASSERT_EQ(isPrime(33), false);
}

