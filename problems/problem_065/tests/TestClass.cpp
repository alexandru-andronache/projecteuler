#include "TestClass.h"
#include "../test.h"

namespace problem_065 {
    TEST_F(Test_problem_065, solve_test) {
        ASSERT_EQ(solve(10), 17);
    }

    TEST_F(Test_problem_065, solve_real_test) {
        ASSERT_EQ(solve(100), 272);
    }
}