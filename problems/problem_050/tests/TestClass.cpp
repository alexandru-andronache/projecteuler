#include "TestClass.h"
#include "../test.h"

namespace problem_050 {
    TEST_F(Test_problem_050, solve_test) {
        ASSERT_EQ(solve(100), 41);
        ASSERT_EQ(solve(1000), 953);
    }

    TEST_F(Test_problem_050, solve_real_test) {
        ASSERT_EQ(solve(1000000), 997651);
    }
}