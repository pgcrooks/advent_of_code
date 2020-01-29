#include "intcode.hpp"

#include <sstream>

namespace advent
{

IntCode::IntCode()
{}

void IntCode::process(std::vector<int> & input)
{
    int index = 0;
    while (index < input.size())
    {
        switch (input[index])
        {
        case add:
        {
            int in_index_1 = input[index+1];
            int in_index_2 = input[index+2];
            int out_index = input[index+3];

            // Carry out the operation
            input[out_index] = input[in_index_1] + input[in_index_2];

            // Move past this operation
            index += 3;
            break;
        }

        case multiply:
        {
            int in_index_1 = input[index+1];
            int in_index_2 = input[index+2];
            int out_index = input[index+3];

            // Carry out the operation
            input[out_index] = input[in_index_1] * input[in_index_2];

            // Move past this operation
            index += 3;
            break;
        }

        case end:
        {
            return;
        }

        default:
            std::stringstream ss;
            ss << "Invalid OpCode: " << input[index];
            throw IntCodeException(ss.str());
        }
        index++;
    }
}

}