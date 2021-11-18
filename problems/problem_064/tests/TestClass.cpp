#include "TestClass.h"
#include "../test.h"

namespace problem_064 {
    TEST_F(Test_problem_064, solve_test) {
        ASSERT_EQ(solve(13), 4);
    }

    TEST_F(Test_problem_064, solve_real_test) {
        ASSERT_EQ(solve(10000), 1322);
    }
}