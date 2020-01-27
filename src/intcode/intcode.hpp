#ifndef _INTCODE_HPP_
#define _INTCODE_HPP_

#include <vector>

namespace advent
{

/**
 * @brief  Opcode
 * @details Tell me what to do.
 */
enum opcode
{
    add = 1,        /** Next 3 ints: 2 input positions and 1 output location */
    multiply = 2,   /** Next 3 ints: 2 input positions and 1 output location */
    end = 99        /** End */
};

/**
 * @brief   IntCode
 * @details Operations are always 4 ints long.
 */
class IntCode
{
public:
    IntCode();

    void process(std::vector<int> & input);

private:
};

}

#endif
