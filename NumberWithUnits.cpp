#include "NumberWithUnits.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <stdio.h>

using namespace std;

namespace ariel
{
    void NumberWithUnits::read_units(ifstream &file)
    {
        cout << "reading from file" << endl;
    }

    NumberWithUnits operator+(const NumberWithUnits &num1, const NumberWithUnits &num2)
    {
        return num1;
    }
    NumberWithUnits operator++(const NumberWithUnits &num1)
    {
        return num1;
    }
    NumberWithUnits operator++(const NumberWithUnits &num1, int)
    {
        return num1;
    }
    NumberWithUnits operator+=(NumberWithUnits &num1, const NumberWithUnits &num2)
    {
        return num1;
    }

    NumberWithUnits operator-(const NumberWithUnits &num1, const NumberWithUnits &num2)
    {
        return num1;
    }
    NumberWithUnits operator-(const NumberWithUnits &num1)
    {
        return num1;
    }
    NumberWithUnits operator--(const NumberWithUnits &num1)
    {
        return num1;
    }
    NumberWithUnits operator--(const NumberWithUnits &num1, int)
    {
        return num1;
    }
    NumberWithUnits operator-=(NumberWithUnits &num1, const NumberWithUnits &num2)
    {
        return num1;
    }

    NumberWithUnits operator*(const double num1, const NumberWithUnits &num2)
    {
        return num2;
    }
    NumberWithUnits operator*(const NumberWithUnits &num1, const double num2){
        return num1;
    }

    bool operator==(const NumberWithUnits &num1, const NumberWithUnits &num2)
    {
        return false;
    }
    bool operator<(const NumberWithUnits &num1, const NumberWithUnits &num2)
    {
        return false;
    }
    bool operator<=(const NumberWithUnits &num1, const NumberWithUnits &num2)
    {
        return false;
    }
    bool operator>(const NumberWithUnits &num1, const NumberWithUnits &num2)
    {
        return false;
    }
    bool operator>=(const NumberWithUnits &num1, const NumberWithUnits &num2)
    {
        return false;
    }
    bool operator!=(const NumberWithUnits &num1, const NumberWithUnits &num2)
    {
        return false;
    }

    std::istream &operator>>(std::istream &in, NumberWithUnits &num1)
    {
        return in;
    }
    std::ostream &operator<<(std::ostream &out, const NumberWithUnits &num1)
    {
        return out;
    }
}