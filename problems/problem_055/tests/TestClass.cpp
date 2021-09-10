#include "TestClass.h"
#include "../test.h"

namespace problem_055 {
    TEST_F(Test_problem_055, solve_real_test) {
        ASSERT_EQ(solve(), 249);
    }
}