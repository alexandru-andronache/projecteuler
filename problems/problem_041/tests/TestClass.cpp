#include "TestClass.h"
#include "../test.h"

namespace problem_041 {
    TEST_F(Test_problem_041, solve_real_test) {
        ASSERT_EQ(solve(), 7652413);
    }
}