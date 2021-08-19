#include "TestClass.h"
#include "../test.h"

namespace problem_019 {
    TEST_F(Test_problem_019, solve_real_test) {
        ASSERT_EQ(solve(), 171);
    }
}