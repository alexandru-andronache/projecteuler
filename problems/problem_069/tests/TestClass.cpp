#include "TestClass.h"
#include "../test.h"

namespace problem_069 {
    TEST_F(Test_problem_069, solve_test) {
        ASSERT_EQ(solve(10), 6);
    }

    TEST_F(Test_problem_069, solve_real_test) {
        ASSERT_EQ(solve(1000000), 510510);
    }
}