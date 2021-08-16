#include "TestClass.h"
#include "../test.h"

namespace problem_008 {
    TEST_F(Test_problem_008, solve_test) {
        ASSERT_EQ(solve(4), 5832);
    }

    TEST_F(Test_problem_008, solve_real_test) {
        ASSERT_EQ(solve(13), 23514624000);
    }
}