#include "TestClass.h"
#include "../test.h"

namespace problem_032 {
    TEST_F(Test_problem_032, solve_real_test) {
        ASSERT_EQ(solve(), 45228);
    }
}