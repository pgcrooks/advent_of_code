#ifndef _MODULE_HPP_
#define _MODULE_HPP_

#include <string>

namespace advent
{

class Module
{
public:
    Module(std::string const & name, int mass);

    int calculate_fuel() const;

private:
    std::string name_;
    int mass_;
};

}

#endif
