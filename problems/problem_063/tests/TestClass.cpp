#include "TestClass.h"
#include "../test.h"

namespace problem_063 {
    TEST_F(Test_problem_063, solve_real_test) {
        ASSERT_EQ(solve(), 49);
    }
}