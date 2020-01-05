#include <math.h>

#include "module.hpp"

namespace advent
{

Module::Module(int mass)
:   mass_(mass)
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
