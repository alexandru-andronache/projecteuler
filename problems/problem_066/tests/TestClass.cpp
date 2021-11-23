#include "TestClass.h"
#include "../test.h"

namespace problem_066 {
    TEST_F(Test_problem_066, solve_test) {
        ASSERT_EQ(solve(7), 5);
    }

    TEST_F(Test_problem_066, solve_real_test) {
        ASSERT_EQ(solve(1000), 661);
    }
}