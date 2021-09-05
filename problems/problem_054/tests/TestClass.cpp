#include "TestClass.h"
#include "../test.h"

namespace problem_054 {
    TEST_F(Test_problem_054, solve_real_test) {
        ASSERT_EQ(solve(), 376);
    }
}