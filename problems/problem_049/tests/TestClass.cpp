#include "TestClass.h"
#include "../test.h"

namespace problem_049 {
    TEST_F(Test_problem_049, solve_real_test) {
        ASSERT_EQ(solve(), "296962999629");
    }
}