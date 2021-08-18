#include "TestClass.h"
#include "../test.h"

namespace problem_017 {
    TEST_F(Test_problem_017, solve_test) {
        ASSERT_EQ(solve(5), 19);
    }

    TEST_F(Test_problem_017, solve_real_test) {
        ASSERT_EQ(solve(1000), 21124);
    }
}