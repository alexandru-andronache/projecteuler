#include "TestClass.h"
#include "../test.h"

namespace problem_031 {
    TEST_F(Test_problem_031, solve_real_test) {
        ASSERT_EQ(solve(200), 73682);
    }
}