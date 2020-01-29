#include <gtest/gtest.h>

#include <intcode.hpp>

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

TEST_F(IntCodeTest, ProcessWhenInvalidOpCodeWillThrowException)
{
    std::vector<int> input = {1010};

    EXPECT_THROW(
        int_code_.process(input),
        IntCodeException);
}

TEST_P(IntCodeTest, WIP)
{
    inout values = GetParam();

    std::vector<int> input = values.first;
    std::vector<int> expected_output = values.second;

    int_code_.process(input);
    EXPECT_EQ(expected_output, input);
}

INSTANTIATE_TEST_SUITE_P(
    ExampleValues,
    IntCodeTest,
    testing::Values(
        inout({1, 0, 0, 0, 99}, {2, 0, 0, 0, 99}),
        inout({2, 3, 0, 3, 99}, {2, 3, 0, 6, 99}),
        inout({2, 4, 4, 5, 99, 0}, {2, 4, 4, 5, 99, 9801}),
        inout({1, 1, 1, 4, 99, 5, 6, 0, 99}, {30, 1, 1, 4, 2, 5, 6, 0, 99})));

}
