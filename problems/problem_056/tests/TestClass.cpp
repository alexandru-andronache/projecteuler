#include "TestClass.h"
#include "../test.h"

namespace problem_056 {
    TEST_F(Test_problem_056, solve_real_test) {
        ASSERT_EQ(solve(), 972);
    }
}