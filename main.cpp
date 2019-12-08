#include <iostream>

#include "module.hpp"

int main(int argc, char *argv[])
{
    std::cout << "Advent of Code" << std::endl;

    advent::Module mod1("mod1", 1969);
    std::cout << "Fuel needed = " << mod1.calculate_fuel() << std::endl;

    return 0;
}
