#include "TestClass.h"
#include "../test.h"

namespace problem_011 {
    TEST_F(Test_problem_011, solve_test) {
        ASSERT_EQ(solve(3), 811502);
    }

    TEST_F(Test_problem_011, solve_real_test) {
        ASSERT_EQ(solve(4), 70600674);
    }
}