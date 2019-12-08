#include <math.h>
#include <string>

#include "module.hpp"

namespace advent
{

Module::Module(std::string name, int mass)
:   name_(name),
    mass_(mass)
{
}

int Module::calculate_fuel() const
{
    float fuel_needed = mass_ / 3;
    fuel_needed = floor(fuel_needed);
    fuel_needed -= 2;
    return fuel_needed;
}

}
