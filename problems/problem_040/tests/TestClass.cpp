#include "TestClass.h"
#include "../test.h"

namespace problem_040 {
    TEST_F(Test_problem_040, solve_real_test) {
        ASSERT_EQ(solve(), 210);
    }
}