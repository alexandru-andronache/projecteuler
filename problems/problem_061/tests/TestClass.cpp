#include "TestClass.h"
#include "../test.h"

namespace problem_061 {
    TEST_F(Test_problem_061, solve_real_test) {
        ASSERT_EQ(solve(), 28684);
    }
}