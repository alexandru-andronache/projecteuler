#include "TestClass.h"
#include "../test.h"

namespace problem_043 {
    TEST_F(Test_problem_043, solve_real_test) {
        ASSERT_EQ(solve(), 16695334890);
    }
}