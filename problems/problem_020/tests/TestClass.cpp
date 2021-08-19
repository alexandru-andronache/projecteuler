#include "TestClass.h"
#include "../test.h"

namespace problem_020 {
    TEST_F(Test_problem_020, solve_test) {
        ASSERT_EQ(solve(10), 27);
    }

    TEST_F(Test_problem_020, solve_real_test) {
        ASSERT_EQ(solve(100), 648);
    }
}