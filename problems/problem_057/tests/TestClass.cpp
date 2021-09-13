#include "TestClass.h"
#include "../test.h"

namespace problem_057 {
    TEST_F(Test_problem_057, solve_real_test) {
        ASSERT_EQ(solve(), 153);
    }
}