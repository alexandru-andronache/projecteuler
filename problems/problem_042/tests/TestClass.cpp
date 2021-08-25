#include "TestClass.h"
#include "../test.h"

namespace problem_042 {
    TEST_F(Test_problem_042, solve_real_test) {
        ASSERT_EQ(solve(), 162);
    }
}