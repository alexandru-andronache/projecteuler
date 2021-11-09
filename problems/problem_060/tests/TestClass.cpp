#include "TestClass.h"
#include "../test.h"

namespace problem_060 {
    TEST_F(Test_problem_060, solve_test) {
        ASSERT_EQ(solve(4), 792);
    }

    TEST_F(Test_problem_060, solve_real_test) {
        ASSERT_EQ(solve(5), 26033);
    }
}