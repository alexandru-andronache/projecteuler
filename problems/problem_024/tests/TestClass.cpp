#include "TestClass.h"
#include "../test.h"

namespace problem_024 {
    TEST_F(Test_problem_024, solve_test) {
        ASSERT_EQ(solve(50, 4), "20143");
    }

    TEST_F(Test_problem_024, solve_real_test) {
        ASSERT_EQ(solve(1000000, 9), "2783915460");
    }
}