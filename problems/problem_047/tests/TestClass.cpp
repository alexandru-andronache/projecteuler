#include "TestClass.h"
#include "../test.h"

namespace problem_047 {
    TEST_F(Test_problem_047, solve_test) {
        ASSERT_EQ(solve(3), 644);
    }

    TEST_F(Test_problem_047, solve_real_test) {
        ASSERT_EQ(solve(4), 134043);
    }
}