#include "TestClass.h"
#include "../test.h"

namespace problem_014 {
    TEST_F(Test_problem_014, solve_test) {
        ASSERT_EQ(solve(15), 9);
    }

    TEST_F(Test_problem_014, solve_real_test) {
        ASSERT_EQ(solve(1000000), 837799);
    }
}