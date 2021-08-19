#include "TestClass.h"
#include "../test.h"

namespace problem_022 {
    TEST_F(Test_problem_022, solve_real_test) {
        ASSERT_EQ(solve(), 871198282);
    }
}