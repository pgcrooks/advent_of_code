#include <gtest/gtest.h>

#include <intcode.hpp>
#include <iostream>

namespace advent
{

typedef std::pair<std::vector<int>, std::vector<int>> inout;

class IntCodeTest : public ::testing::TestWithParam<inout>
{
protected:
    IntCodeTest()
    :   int_code_()
    {}

    IntCode int_code_;
};

TEST_F(IntCodeTest, ConstructorWillConstructIntcode)
{
    IntCode machine();
}

TEST_P(IntCodeTest, WIP)
{
    inout values = GetParam();

    std::vector<int> input = values.first;
    std::vector<int> output = values.second;

    std::cout << "BEFORE: ";
    for (auto x: input)
    {
        std::cout << x << ", ";
    }
    std::cout << std::endl;

    int_code_.process(input);

    EXPECT_EQ(output, input);

    std::cout << "AFTER: ";
    for (auto x: input)
    {
        std::cout << x << ", ";
    }
    std::cout << std::endl;
}

// std::vector<int> in{1, 0, 0, 0, 99};
// std::vector<int> out{2, 0, 0, 0, 99};

INSTANTIATE_TEST_SUITE_P(
    ExampleValues,
    IntCodeTest,
    testing::Values(
        inout({1, 0, 0, 0, 99}, {2, 0, 0, 0, 99}),
        inout({2, 3, 0, 3, 99}, {2, 3, 0, 6, 99})));

}
