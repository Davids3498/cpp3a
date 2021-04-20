#include "doctest.h"
#include "NumberWithUnits.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

using namespace std;
using namespace ariel;

TEST_CASE("Basic")
{
    ifstream units_file{"units.txt"};
    NumberWithUnits::read_units(units_file);
    NumberWithUnits A1{1, "km"};
    NumberWithUnits A2{100, "m"};
    NumberWithUnits A3{7, "g"};
    NumberWithUnits A4{16, "kg"};
    NumberWithUnits A5{420, "min"};
    NumberWithUnits A6{34, "sec"};
    NumberWithUnits A7{98, "USD"};

    CHECK(A1 == NumberWithUnits{1, "km"});
    CHECK(A2 == NumberWithUnits{100, "m"});
    CHECK(A3 == NumberWithUnits{7, "g"});
    CHECK(A4 == NumberWithUnits{16, "kg"});
    CHECK(A5 == NumberWithUnits{420, "min"});
    CHECK(A6 == NumberWithUnits{34, "sec"});
    CHECK(A7 == NumberWithUnits{98, "USD"});
}

TEST_CASE("Operator +")
{
    ifstream units_file{"units.txt"};
    NumberWithUnits::read_units(units_file);
    NumberWithUnits A1{1, "km"};
    NumberWithUnits A2{100, "m"};
    CHECK(A1 + A2 == NumberWithUnits{1.1, "km"});

    NumberWithUnits A3{7, "g"};
    NumberWithUnits A4{16, "kg"};
    CHECK_THROWS(A1 + A3);
    CHECK(A3 + A4 == NumberWithUnits{16.007, "kg"});

    NumberWithUnits A5{1, "hour"};
    NumberWithUnits A6{30, "min"};
    NumberWithUnits A7{3600, "sec"};
    CHECK_THROWS(A5 + A3);
    CHECK(A5 + A6 + A7 == NumberWithUnits{2.5, "hour"});

    NumberWithUnits A8{98, "USD"};
    NumberWithUnits A9{6.66, "ILS"};
    CHECK_THROWS(A5 + A8);
    CHECK(A8 + A9 == NumberWithUnits{100, "USD"});

    NumberWithUnits A10{999, "m"};
    CHECK(A10++ == NumberWithUnits{999, "m"});
    CHECK(A10 == NumberWithUnits{1, "km"});
    CHECK(++A10 == NumberWithUnits{2, "km"});
    A10 += A1;
    CHECK(A10 == NumberWithUnits{3, "km"});
}

TEST_CASE("Operator -")
{
    ifstream units_file{"units.txt"};
    NumberWithUnits::read_units(units_file);
    NumberWithUnits A1{1, "km"};
    NumberWithUnits A2{100, "m"};
    CHECK(A1 - A2 == NumberWithUnits{0.9, "km"});
    -A1;
    CHECK(A1 == NumberWithUnits{-0.9, "km"});

    NumberWithUnits A3{7, "g"};
    NumberWithUnits A4{16, "kg"};
    CHECK_THROWS(A1 - A3);
    CHECK(A3 - A4 == NumberWithUnits{15.993, "kg"});

    NumberWithUnits A5{1, "hour"};
    NumberWithUnits A6{30, "min"};
    CHECK_THROWS(A5 - A3);
    CHECK(A5 - A6 == NumberWithUnits{.5, "hour"});

    NumberWithUnits A8{98, "USD"};
    NumberWithUnits A9{6.66, "ILS"};
    CHECK_THROWS(A5 - A8);
    CHECK(A8 - A9 == NumberWithUnits{96, "USD"});

    NumberWithUnits A10{1001, "m"};
    CHECK(A10-- == NumberWithUnits{1001, "m"});
    CHECK(A10 == NumberWithUnits{1, "km"});
    CHECK(--A10 == NumberWithUnits{0, "km"});
    A10 += A1;
    CHECK(A10 == NumberWithUnits{1, "km"});
}

TEST_CASE("Operator *")
{
    ifstream units_file{"units.txt"};
    NumberWithUnits::read_units(units_file);
    NumberWithUnits A1{1, "km"};
    NumberWithUnits A2{100, "m"};
    NumberWithUnits A3 = A1 * 2;
    CHECK(A3 == NumberWithUnits{2, "km"});
    NumberWithUnits A4 = 10 * A2;
    CHECK(A4 == NumberWithUnits{1, "km"});
}

TEST_CASE("Operator bool")
{
    ifstream units_file{"units.txt"};
    NumberWithUnits::read_units(units_file);
    NumberWithUnits A1{1, "km"};
    NumberWithUnits A2{100, "m"};
    CHECK((A1 < A2) == false);
    CHECK((A1 > A2) == true);

    NumberWithUnits A3{700, "g"};
    NumberWithUnits A4{1, "kg"};
    CHECK((A3 > A4) == false);
    A4--;
    CHECK((A3 > A4) == true);

    NumberWithUnits A5{1000, "g"};
    CHECK((A5 > A4) == false);
    CHECK((A5 < A4) == false);
    CHECK((A5 != A4) == false);
    CHECK((A5 == A4) == true);
    CHECK((A5 >= A4) == true);
    CHECK((A5 <= A4) == true);

    NumberWithUnits A6{1, "g"};
    A5 -= A6;
    CHECK((A5 > A4) == false);
    CHECK((A5 < A4) == true);
    CHECK((A5 != A4) == true);
    CHECK((A5 == A4) == false);
    CHECK((A5 >= A4) == false);
    CHECK((A5 <= A4) == true);
}

TEST_CASE("Not exisring units")
{
    ifstream units_file{"units.txt"};
    NumberWithUnits::read_units(units_file);
    CHECK_THROWS(NumberWithUnits A1(1, "gcc"));
    CHECK_THROWS(NumberWithUnits A2(1, "vs"));
    CHECK_THROWS(NumberWithUnits A3(1, "clang"));
    CHECK_THROWS(NumberWithUnits A4(1, "cpp"));
    CHECK_THROWS(NumberWithUnits A5(1, "hpp"));
}