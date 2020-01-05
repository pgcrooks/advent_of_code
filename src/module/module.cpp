#include <math.h>

#include "module.hpp"

namespace advent
{

int calculate_fuel_from_mass(int mass)
{
    float fuel_needed = mass / 3;
    fuel_needed = floor(fuel_needed);
    fuel_needed -= 2;

    // Less than zero requires wishes
    if (fuel_needed < 0)
    {
        fuel_needed = 0;
    }
    return fuel_needed;
}

Module::Module(int mass)
:   mass_(mass)
{
}

int Module::calculate_fuel() const
{
    int fuel_needed = calculate_fuel_from_mass(mass_);
    int total_fuel = 0;

    while (fuel_needed > 0)
    {
        total_fuel += fuel_needed;
        fuel_needed = calculate_fuel_from_mass(fuel_needed);
    }

    return total_fuel;
}

}
