#include "TestClass.h"
#include "../test.h"

namespace problem_018 {
    TEST_F(Test_problem_018, solve_test) {
        ASSERT_EQ(solve("../problems/problem_018/input/input_test.in"), 23);
    }

    TEST_F(Test_problem_018, solve_real_test) {
        ASSERT_EQ(solve("../problems/problem_018/input/input.in"), 1074);
    }
}