#include "TestClass.h"
#include "../test.h"

namespace problem_012 {
    TEST_F(Test_problem_012, solve_test) {
        ASSERT_EQ(solve(5), 28);
    }

    TEST_F(Test_problem_012, solve_real_test) {
        ASSERT_EQ(solve(500), 76576500);
    }
}