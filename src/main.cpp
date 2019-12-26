#include <iostream>
#include <vector>

#include <aoc_config.h>
#include <io.hpp>
#include <module.hpp>

int main(int argc, char *argv[])
{
    std::cout << "Advent of Code "
        << advent_of_code_VERSION_MAJOR
        << "."
        << advent_of_code_VERSION_MINOR
        << std::endl;

    advent::Module mod1("mod1", 1969);
    std::cout << "Fuel needed = " << mod1.calculate_fuel() << std::endl;

    advent::Reader reader("/home/pgcrooks/code/advent_of_code/input.txt");
    std::vector<int> input_values = reader.get_input();

    int total_fuel = 0;
    for (auto x: input_values)
    {
        std::cout << x << std::endl;
        advent::Module mod("foo", x);
        total_fuel += mod.calculate_fuel();
    }

    std::cout << "Total fuel required: " << total_fuel << std::endl;

    return 0;
}
