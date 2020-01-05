#ifndef _MODULE_HPP_
#define _MODULE_HPP_

namespace advent
{

class Module
{
public:
    explicit Module(int mass);

    int calculate_fuel() const;

private:
    int mass_;
};

}

#endif
