#include "TestClass.h"
#include "../test.h"

namespace problem_045 {
    TEST_F(Test_problem_045, solve_real_test) {
        ASSERT_EQ(solve(), 1533776805);
    }
}