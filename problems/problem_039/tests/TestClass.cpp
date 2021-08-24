#include "TestClass.h"
#include "../test.h"

namespace problem_039 {
    TEST_F(Test_problem_039, solve_real_test) {
        ASSERT_EQ(solve(1000), 840);
    }
}