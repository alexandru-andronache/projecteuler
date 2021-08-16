#include "TestClass.h"
#include "../test.h"

namespace problem_010 {
    TEST_F(Test_problem_010, solve_test) {
        ASSERT_EQ(solve(10), 17);
    }

    TEST_F(Test_problem_010, solve_real_test) {
        ASSERT_EQ(solve(2000000), 142913828922);
    }
}