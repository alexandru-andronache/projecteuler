#include "TestClass.h"
#include "../test.h"

namespace problem_053 {
    TEST_F(Test_problem_053, solve_real_test) {
        ASSERT_EQ(solve(100), 4075);
    }
}