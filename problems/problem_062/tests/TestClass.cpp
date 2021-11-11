#include "TestClass.h"
#include "../test.h"

namespace problem_062 {
    TEST_F(Test_problem_062, solve_test) {
        ASSERT_EQ(solve(3), 41063625);
    }

    TEST_F(Test_problem_062, solve_real_test) {
        ASSERT_EQ(solve(5), 127035954683);
    }
}