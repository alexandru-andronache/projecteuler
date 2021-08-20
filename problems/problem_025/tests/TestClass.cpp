#include "TestClass.h"
#include "../test.h"

namespace problem_025 {
    TEST_F(Test_problem_025, solve_test) {
        ASSERT_EQ(solve(3), 12);
    }

    TEST_F(Test_problem_025, solve_real_test) {
        ASSERT_EQ(solve(1000), 4782);
    }
}