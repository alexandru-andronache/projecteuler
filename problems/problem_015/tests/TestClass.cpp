#include "TestClass.h"
#include "../test.h"

namespace problem_015 {
    TEST_F(Test_problem_015, solve_test) {
        ASSERT_EQ(solve(2), 6);
    }

    TEST_F(Test_problem_015, solve_real_test) {
        ASSERT_EQ(solve(20), 137846528820);
    }
}