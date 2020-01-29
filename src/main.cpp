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

    if (!result.count("day"))
    {
        std::cout << "A day must be provided, exit." << std::endl;
        exit(1);
    }

    if (!result.count("file"))
    {
        std::cout << "An input file must be provided, exit." << std::endl;
        exit(1);
    }

    return result;
}

void run_day_1(std::vector<int> input)
{
    std::cout << "Fuel Calculator" << std::endl;

    int total_fuel = 0;
    for (auto x: input)
    {
        advent::Module mod(x);
        total_fuel += mod.calculate_fuel();
    }

    std::cout << "Total fuel required: " << total_fuel << std::endl;
}

void run_day_2(std::vector<int> input)
{
    std::cout << "IntCode Computer" << std::endl;

    advent::IntCode int_code();
}

int main(int argc, char *argv[])
{
    auto result = parse_command_line(argc, argv);

    advent::Reader reader(result["file"].as<std::string>());
    std::vector<int> input_values;

    try
    {
        input_values = reader.get_input();
    }
    catch(const std::exception& e)
    {
        std::cerr << "Reader failed: " << e.what() << std::endl;
    }

    switch (result["day"].as<int>())
    {
    case 1:
        run_day_1(input_values);
        break;

    case 2:
        run_day_2(input_values);
        break;

    default:
        std::cout << "Unrecognised day." << std::endl;
    }

    return 0;
}
