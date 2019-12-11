#include <gtest/gtest.h>

#include <module.hpp>

namespace advent
{

TEST(TestModule, ConstructorReturnsModule)
{
    advent::Module mod1("mod1", 1969);
}

}
