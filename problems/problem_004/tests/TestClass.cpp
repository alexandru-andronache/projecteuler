#include "TestClass.h"
#include "../test.h"

namespace problem_004 {
    TEST_F(Test_problem_004, solve_test) {
        ASSERT_EQ(solve(10, 99), 9009);
    }

    TEST_F(Test_problem_004, solve_real_test) {
        ASSERT_EQ(solve(100, 999), 906609);
    }
}