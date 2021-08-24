#include "TestClass.h"
#include "../test.h"

namespace problem_037 {
    TEST_F(Test_problem_037, solve_real_test) {
        ASSERT_EQ(solve(), 748317);
    }
}