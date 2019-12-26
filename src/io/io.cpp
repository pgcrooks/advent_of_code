#include <fstream>
#include <string>
#include <vector>

#include "io.hpp"

#include <iostream> //TODO

namespace advent
{

ReaderException::ReaderException()
{
}

Reader::Reader(std::string const & data_file)
:   data_file_(data_file)
{}

std::vector<int> Reader::get_input() const
{
    std::vector<int> data;

    std::ifstream input_data("/home/pgcrooks/code/advent_of_code/input.txt");
    std::string line;
    if (input_data.is_open())
    {
        while (getline(input_data, line))
        {
            data.emplace_back(std::atoi(line.c_str()));
        }
        input_data.close();
    }
    else
    {
        throw ReaderException();
    }

    return data;
}

}
