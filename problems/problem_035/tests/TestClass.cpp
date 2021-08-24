#include "TestClass.h"
#include "../test.h"

namespace problem_035 {
    TEST_F(Test_problem_035, solve_test) {
        ASSERT_EQ(solve(100), 13);
    }

    TEST_F(Test_problem_035, solve_real_test) {
        ASSERT_EQ(solve(1000000), 55);
    }
}