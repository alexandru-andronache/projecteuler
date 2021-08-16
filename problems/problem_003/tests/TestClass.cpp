#include "TestClass.h"
#include "../test.h"

namespace problem_003 {
    TEST_F(Test_problem_003, solve_test) {
        ASSERT_EQ(solve(13195), 29);
    }

    TEST_F(Test_problem_003, solve_real_test) {
        ASSERT_EQ(solve(600851475143), 6857);
    }
}