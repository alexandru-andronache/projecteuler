#include "TestClass.h"
#include "../test.h"

namespace problem_033 {
    TEST_F(Test_problem_033, solve_real_test) {
        ASSERT_EQ(solve(), 100);
    }
}