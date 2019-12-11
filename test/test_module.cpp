#include <iostream>

#include <gtest/gtest.h>

#include <module.hpp>

namespace advent
{

TEST(TestModule, ConstructorReturnsModule)
{
    advent::Module mod1("mod1", 1969);
}


class ModuleNumberTest : public ::testing::TestWithParam<int>
{
public:
    ModuleNumberTest()
    {}
};

TEST_P(ModuleNumberTest, Examples)
{
    Module mod("mod1", GetParam());
    std::cout << mod.calculate_fuel() << std::endl;
}

INSTANTIATE_TEST_SUITE_P(ExampleValues,
    ModuleNumberTest,
    testing::Values(12, 14, 1969, 100756));

}
