#include "FractionTest.h"
#include "fraction.h"

using namespace fraction;

TEST_F(FractionTest, compare_fractions_1)
{
    Fraction f1(10, 20);
    Fraction f2(10, 30);

    ASSERT_FALSE(f1 < f2);
}

TEST_F(FractionTest, compare_fractions_2)
{
    Fraction f1(5, 8);
    Fraction f2(6, 8);

    ASSERT_TRUE(f1 < f2);
}