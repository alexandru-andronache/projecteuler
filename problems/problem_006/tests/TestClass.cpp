#include "TestClass.h"
#include "../test.h"

namespace problem_006 {
    TEST_F(Test_problem_006, solve_test) {
        ASSERT_EQ(solve(10), 2640);
    }

    TEST_F(Test_problem_006, solve_real_test) {
        ASSERT_EQ(solve(100), 25164150);
    }
}