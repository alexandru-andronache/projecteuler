#include "TestClass.h"
#include "../test.h"

namespace problem_026 {
    TEST_F(Test_problem_026, solve_test) {
        ASSERT_EQ(solve(10), 7);
    }

    TEST_F(Test_problem_026, solve_real_test) {
        ASSERT_EQ(solve(1000), 983);
    }
}