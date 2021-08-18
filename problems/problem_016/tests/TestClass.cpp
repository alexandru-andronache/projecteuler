#include "TestClass.h"
#include "../test.h"

namespace problem_016 {
    TEST_F(Test_problem_016, solve_test) {
        ASSERT_EQ(solve(15), 26);
    }

    TEST_F(Test_problem_016, solve_real_test) {
        ASSERT_EQ(solve(1000), 1366);
    }
}