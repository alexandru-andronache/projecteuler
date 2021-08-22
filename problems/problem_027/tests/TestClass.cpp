#include "TestClass.h"
#include "../test.h"

namespace problem_027 {
    TEST_F(Test_problem_027, solve_real_test) {
        ASSERT_EQ(solve(), -59231);
    }
}