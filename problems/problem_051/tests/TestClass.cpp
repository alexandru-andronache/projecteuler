#include "TestClass.h"
#include "../test.h"

namespace problem_051 {
    TEST_F(Test_problem_051, solve_test) {
        ASSERT_EQ(solve(7), 56003);
    }

    TEST_F(Test_problem_051, solve_real_test) {
        ASSERT_EQ(solve(8), 121313);
    }
}