#include "TestClass.h"
#include "../test.h"

namespace problem_059 {
    TEST_F(Test_problem_059, solve_real_test) {
        ASSERT_EQ(solve(), 129448);
    }
}