#include <iostream>
#include <sstream>
#include <vector>

#include <cxxopts.hpp>

#include <aoc_config.h>
#include <io.hpp>
#include <intcode.hpp>
#include <module.hpp>

cxxopts::ParseResult parse_command_line(int argc, char *argv[])
{
    std::stringstream ss;
    ss << "Advent of Code "
        << advent_of_code_VERSION_MAJOR
        << "."
        << advent_of_code_VERSION_MINOR;

    cxxopts::Options options(argv[0], ss.str());

    options.add_options()
        ("d, day", "day to run", cxxopts::value<int>(), "N")
        ("f, file", "input file", cxxopts::value<std::string>(), "FILE")
        ("h, help", "help");

    auto result = options.parse(argc, argv);

    if (result.count("help"))
    {
        std::cout << options.help({"", "Group"}) << std::endl;
        exit(0);
    }

    return result;
}

void run_day_1()
{
    std::cout << "Fuel Calculator" << std::endl;

    try
    {
        advent::Reader reader("/home/pgcrooks/code/advent_of_code/input.txt");
        std::vector<int> input_values = reader.get_input();

        int total_fuel = 0;
        for (auto x: input_values)
        {
            advent::Module mod(x);
            total_fuel += mod.calculate_fuel();
        }

        std::cout << "Total fuel required: " << total_fuel << std::endl;
    }
    catch(advent::ReaderException)
    {
        std::cerr << "Failed to read input data" << std::endl;
    }    
}

void run_day_2()
{
    std::cout << "IntCode Computer" << std::endl;

    advent::IntCode int_code();
}

int main(int argc, char *argv[])
{
    auto result = parse_command_line(argc, argv);

    if (result.count("day"))
    {
        switch (result["day"].as<int>())
        {
        case 1:
            run_day_1();
            break;

        case 2:
            run_day_2();
            break;

        default:
            std::cout << "Unrecognised day." << std::endl;
        }
    }
    else
    {
        std::cout << "A day must be provided, doing nothing" << std::endl;
    }

    return 0;
}
