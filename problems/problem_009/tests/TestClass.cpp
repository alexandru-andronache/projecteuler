#include "TestClass.h"
#include "../test.h"

namespace problem_009 {
    TEST_F(Test_problem_009, solve_test) {
        ASSERT_EQ(solve(12), 60);
    }

    TEST_F(Test_problem_009, solve_real_test) {
        ASSERT_EQ(solve(1000), 31875000);
    }
}