#include "BigNumber.h"
#include "big_number.h"

using namespace big_number;

TEST_F(BigNumberTest, add_number) {
    BigNumber test(123);
    BigNumber test2(234);
    BigNumber sum(357);
    test += test2;

    ASSERT_EQ(test, sum);
}

TEST_F(BigNumberTest, add_number_different_sizes) {
    BigNumber test(123);
    BigNumber test2(2340);
    BigNumber sum(2463);
    test += test2;

    ASSERT_EQ(test, sum);
}

TEST_F(BigNumberTest, add_number_different_sizes_2) {
    BigNumber test(12300);
    BigNumber test2(234);
    BigNumber sum(12534);
    test += test2;

    ASSERT_EQ(test, sum);
}

