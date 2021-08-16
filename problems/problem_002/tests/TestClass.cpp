#include "TestClass.h"
#include "../test.h"

namespace problem_002 {
    TEST_F(Test_problem_002, solve_test) {
        ASSERT_EQ(solve(100), 44);
    }

    TEST_F(Test_problem_002, solve_real_test) {
        ASSERT_EQ(solve(4000000), 4613732);
    }
}