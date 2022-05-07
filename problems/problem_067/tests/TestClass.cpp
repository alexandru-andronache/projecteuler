#include "TestClass.h"
#include "../test.h"

namespace problem_067 {
    TEST_F(Test_problem_067, solve_real_test) {
        ASSERT_EQ(solve("../problems/problem_067/input/input.in"), 7273);
    }
}