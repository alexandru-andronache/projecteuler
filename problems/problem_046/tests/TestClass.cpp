#include "TestClass.h"
#include "../test.h"

namespace problem_046 {
    TEST_F(Test_problem_046, solve_real_test) {
        ASSERT_EQ(solve(), 5777);
    }
}