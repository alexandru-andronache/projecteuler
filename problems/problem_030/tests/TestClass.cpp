#include "TestClass.h"
#include "../test.h"

namespace problem_030 {
    TEST_F(Test_problem_030, solve_test) {
        ASSERT_EQ(solve(4), 19316);
    }

    TEST_F(Test_problem_030, solve_real_test) {
        ASSERT_EQ(solve(5), 0);
    }
}