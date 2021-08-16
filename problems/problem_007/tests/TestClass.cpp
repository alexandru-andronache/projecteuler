#include "TestClass.h"
#include "../test.h"

namespace problem_007 {
    TEST_F(Test_problem_007, solve_test) {
        ASSERT_EQ(solve(6), 13);
    }

    TEST_F(Test_problem_007, solve_real_test) {
        ASSERT_EQ(solve(10001), 104743);
    }
}