#include "TestClass.h"
#include "../test.h"

namespace problem_023 {
    TEST_F(Test_problem_023, solve_real_test) {
        ASSERT_EQ(solve(), 4179871);
    }
}