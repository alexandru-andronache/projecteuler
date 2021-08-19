#include "TestClass.h"
#include "../test.h"

namespace problem_021 {
    TEST_F(Test_problem_021, solve_real_test) {
        ASSERT_EQ(solve(10000), 31626);
    }
}