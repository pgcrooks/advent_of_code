#include <iostream>

#include <aoc_config.h>

#include "module.hpp"

int main(int argc, char *argv[])
{
    std::cout << "Advent of Code "
        << advent_of_code_VERSION_MAJOR
        << "."
        << advent_of_code_VERSION_MINOR
        << std::endl;

    advent::Module mod1("mod1", 1969);
    std::cout << "Fuel needed = " << mod1.calculate_fuel() << std::endl;

    return 0;
}
