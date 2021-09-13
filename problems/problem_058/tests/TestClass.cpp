#include "TestClass.h"
#include "../test.h"

namespace problem_058 {
    TEST_F(Test_problem_058, solve_real_test) {
        ASSERT_EQ(solve(), 26241);
    }
}