#include "TestClass.h"
#include "../test.h"

namespace problem_005 {
    TEST_F(Test_problem_005, solve_test) {
        ASSERT_EQ(solve(10), 2520);
    }

    TEST_F(Test_problem_005, solve_real_test) {
        ASSERT_EQ(solve(20), 232792560);
    }
}