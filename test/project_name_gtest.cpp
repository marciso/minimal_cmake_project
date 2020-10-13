#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "project_name.hpp"

using namespace ::testing;

struct project_name_test : ::testing::Test
{
};

// export GTEST_ALSO_RUN_DISABLED_TESTS=1 to enable disabled tests
TEST_F(project_name_test, DISABLED_test_fail)
{
    FAIL();
}

TEST_F(project_name_test, test_)
{
    EXPECT_THAT(0, Eq(false));
}
