#include "TestClass.h"
#include "../test.h"

namespace problem_001 {
    TEST_F(Test_problem_001, solve_test) {
        ASSERT_EQ(solve(10), 23);
    }

    TEST_F(Test_problem_001, solve_real_test) {
        ASSERT_EQ(solve(1000), 233168);
    }
}