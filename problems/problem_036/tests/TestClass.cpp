#include "TestClass.h"
#include "../test.h"

namespace problem_036 {
    TEST_F(Test_problem_036, solve_real_test) {
        ASSERT_EQ(solve(), 872187);
    }
}