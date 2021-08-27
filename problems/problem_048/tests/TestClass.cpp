#include "TestClass.h"
#include "../test.h"

namespace problem_048 {
    TEST_F(Test_problem_048, solve_test) {
        ASSERT_EQ(solve(10), "0405071317");
    }

    TEST_F(Test_problem_048, solve_real_test) {
        ASSERT_EQ(solve(1000), "9110846700");
    }
}