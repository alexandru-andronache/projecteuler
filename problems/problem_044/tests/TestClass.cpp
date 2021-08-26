#include "TestClass.h"
#include "../test.h"

namespace problem_044 {
    TEST_F(Test_problem_044, solve_real_test) {
        ASSERT_EQ(solve(), 5482660);
    }
}