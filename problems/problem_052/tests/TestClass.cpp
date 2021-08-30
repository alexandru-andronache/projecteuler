#include "TestClass.h"
#include "../test.h"

namespace problem_052 {
    TEST_F(Test_problem_052, solve_real_test) {
        ASSERT_EQ(solve(), 142857);
    }
}