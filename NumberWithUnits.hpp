#pragma once
#include <iostream>
#include <string>
#include <fstream>

namespace ariel
{
    class NumberWithUnits
    {
    public:
        NumberWithUnits(double i, std::string str){}

        static void read_units(std::ifstream &);

        friend NumberWithUnits operator+(const NumberWithUnits &, const NumberWithUnits &);
        friend NumberWithUnits operator++(const NumberWithUnits &);
        friend NumberWithUnits operator++(const NumberWithUnits &, int);
        friend NumberWithUnits operator+=(NumberWithUnits &, const NumberWithUnits &);

        friend NumberWithUnits operator-(const NumberWithUnits &, const NumberWithUnits &);
        friend NumberWithUnits operator-(const NumberWithUnits &);
        friend NumberWithUnits operator--(const NumberWithUnits &);
        friend NumberWithUnits operator--(const NumberWithUnits &, int);
        friend NumberWithUnits operator-=(NumberWithUnits &, const NumberWithUnits &);

        friend NumberWithUnits operator*(const double, const NumberWithUnits &);
        friend NumberWithUnits operator*( const NumberWithUnits &, const double);

        friend bool operator==(const NumberWithUnits &, const NumberWithUnits &);
        friend bool operator<(const NumberWithUnits &, const NumberWithUnits &);
        friend bool operator<=(const NumberWithUnits &, const NumberWithUnits &);
        friend bool operator>(const NumberWithUnits &, const NumberWithUnits &);
        friend bool operator>=(const NumberWithUnits &, const NumberWithUnits &);
        friend bool operator!=(const NumberWithUnits &, const NumberWithUnits &);

        friend std::istream &operator>>(std::istream &, NumberWithUnits &);
        friend std::ostream &operator<<(std::ostream &, const NumberWithUnits &);
    };
}