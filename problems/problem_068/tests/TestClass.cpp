#include "TestClass.h"
#include "../test.h"

namespace problem_068 {
    TEST_F(Test_problem_068, solve_real_test) {
        ASSERT_EQ(solve(), 6531031914842725);
    }
}