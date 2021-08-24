#include "TestClass.h"
#include "../test.h"

namespace problem_038 {
    TEST_F(Test_problem_038, solve_real_test) {
        ASSERT_EQ(solve(), 932718654);
    }
}