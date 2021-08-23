#include "TestClass.h"
#include "../test.h"

namespace problem_029 {
    TEST_F(Test_problem_029, solve_test) {
        ASSERT_EQ(solve(5), 15);
    }

    TEST_F(Test_problem_029, solve_real_test) {
        ASSERT_EQ(solve(100), 9183);
    }
}