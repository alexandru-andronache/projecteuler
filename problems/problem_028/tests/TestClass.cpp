#include "TestClass.h"
#include "../test.h"

namespace problem_028 {
    TEST_F(Test_problem_028, solve_test) {
        ASSERT_EQ(solve(5), 101);
    }

    TEST_F(Test_problem_028, solve_real_test) {
        ASSERT_EQ(solve(1001), 669171001);
    }
}