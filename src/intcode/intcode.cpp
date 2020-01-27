#include "intcode.hpp"

#include <iostream>
#include <sstream>

//TODO: strategy pattern

namespace advent
{
IntCode::IntCode()
{}

void IntCode::process(std::vector<int> & input)
{
    std::cout << "PROCESS: " << input.size() << " values " << std::endl;

    int index = 0;
    while (index < input.size())
    {
        switch (input[index])
        {
        case add:
        {
            std::cout << "ADD" << std::endl;
            int in_index_1 = input[index+1];
            int in_index_2 = input[index+2];
            int out_index = input[index+3];

            std::cout << "in_index_1=" << in_index_1 << ", in_index_2=" << in_index_2 << ", out_index=" << out_index << std::endl;
            input[out_index] = input[in_index_1] + input[in_index_2];

            // Move past this operation
            index += 3;
            break;
        }

        case multiply:
        {
            std::cout << "MULTIPLY" << std::endl;
            int in_index_1 = input[index+1];
            int in_index_2 = input[index+2];
            int out_index = input[index+3];

            std::cout << "in_index_1=" << in_index_1 << ", in_index_2=" << in_index_2 << ", out_index=" << out_index << std::endl;
            input[out_index] = input[in_index_1] * input[in_index_2];

            // Move past this operation
            index += 3;
            break;
            break;
        }

        case end:
        {
            std::cout << "END" << std::endl;
            break;
        }

        default:
            std::cout << "HUH? " << input[index] << std::endl;
        }
        index++;
    }
}

}