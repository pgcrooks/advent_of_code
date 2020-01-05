#include <iostream>

#include <gtest/gtest.h>

#include <module.hpp>

namespace advent
{

TEST(TestModule, ConstructorReturnsModule)
{
    advent::Module mod1(1969);
}


typedef std::pair<int, int> inout;
class ModuleNumberTest : public ::testing::TestWithParam<inout>
{
public:
    ModuleNumberTest()
    {}
};

TEST_P(ModuleNumberTest, Examples)
{
    inout values = GetParam();

    Module mod(values.first);

    ASSERT_EQ(values.second, mod.calculate_fuel());
}

INSTANTIATE_TEST_SUITE_P(ExampleValues,
    ModuleNumberTest,
    testing::Values(inout(12, 2), inout(14, 2), inout(1969, 654), inout(100756, 33583)));

}
