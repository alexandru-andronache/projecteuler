#include "TestClass.h"
#include "../test.h"

namespace problem_034 {
    TEST_F(Test_problem_034, solve_real_test) {
        ASSERT_EQ(solve(0), 40730);
    }
}