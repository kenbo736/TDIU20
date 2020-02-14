#include <string>
#include <iostream>
#include <sstream>

#include "catch.hpp"
#include "Time.h"

//using namespace std;
// här lägger ni era testfall.
// Jobba enligt TDD;
//  1. Lägg till testfall
//  2. Testa
//  3. Lägg till (minsta möjliga) implementation
//  4. Testa alla testfall
//  5. Refaktorera (skriv om) så att allt ser bra ut


TEST_CASE ("Default constructor")
{
    Time t;

    CHECK(t.hour() == 0);
    CHECK(t.minute() == 0);
    CHECK(t.second() == 0);
}

TEST_CASE ( "Constructor with numeric arguments" )
{
    Time t{12,13,14};
    CHECK(t.hour() == 12);
    CHECK(t.minute() == 13);
    CHECK(t.second() == 14);
}

TEST_CASE ("Constructor with faulty argument")
{
    CHECK_THROWS( Time{41,0,0} );
    CHECK_THROWS( Time{0,99,0} );
    CHECK_THROWS( Time{0,0,99} );
}

TEST_CASE ("String constructor")
{
    Time t{"12:23:12"};
    CHECK(t.hour() == 12);
    CHECK(t.minute() == 23);
    CHECK(t.second() == 12);

    SECTION ("Throws as well")
    {
        CHECK_THROWS( Time{"02:11:74"} );
    }
}

TEST_CASE ("am or pm")
{
    Time t{12,12,31};
    CHECK_FALSE(t.is_am());
    Time t2{1,2,3};
    CHECK(t2.is_am());
}

TEST_CASE ("Convert to string" )
{
    CHECK( Time{12,12,12}.to_string()     ==    "12:12:12" );
    CHECK( Time{12, 1, 2}.to_string()     ==    "12:01:02" );
    CHECK( Time{14,33,12}.to_string(true) == "02:33:12 pm" );
}

TEST_CASE ("Conversion to string" )
{
    CHECK( string(Time{2,4,1}) == "02:04:01" );
}

TEST_CASE ("Output operator" )
{
    std::stringstream ss;
    SECTION("Simple output")
    {
        ss << Time{2,5,1};
        CHECK(ss.str() == "02:05:01");
    }
    SECTION("Chained output")
    {
        ss << Time{23,10,32} << "---";
        CHECK(ss.str() == "23:10:32---");
    }
    SECTION("Const time")
    {
        Time const t{23,23,23};
        ss << t;
        CHECK(ss.str() == "23:23:23");
    }
}

TEST_CASE ("addition of a second")
{
    Time t2{1,2,4};
    CHECK(string(t2+Time{0,0,5}) == "01:02:09");
    CHECK(string(t2+Time{0,0,57}) == "01:03:01");
    CHECK(string(t2+Time{0,58,0}) == "02:00:04");
    CHECK(string(t2+Time{1,59,5}) == "03:01:09");
    CHECK(string(t2+Time{0,58,57}) == "02:01:01");
    CHECK(string(t2+Time{0,57,57}) == "02:00:01");
    CHECK(string(t2+Time{0,56,57}) == "01:59:01");
    CHECK(string(t2+Time{22,57,57}) == "00:00:01");
}

TEST_CASE ("subtraction of a second")
{
    Time t2{2,2,4};
    CHECK(string(t2-Time{0,0,1}) == "02:02:03");
    CHECK(string(t2-Time{0,0,5}) == "02:01:59");
    CHECK(string(t2-Time{0,3,0}) == "01:59:04");
    CHECK(string(t2-Time{0,3,5}) == "01:58:59");
    CHECK(string(t2-Time{1,3,5}) == "00:58:59");

}

TEST_CASE ("add of one")
{
    CHECK(string(++Time{0,58,58}) == "00:58:59");
    CHECK(string(++Time{0,58,59}) == "00:59:00");
    CHECK(string(++Time{0,59,59}) == "01:00:00");
}

TEST_CASE ("remove of one")
{
    CHECK(string(--Time{0,58,58}) == "00:58:57");
    CHECK(string(--Time{0,58,0}) == "00:57:59");
    CHECK(string(--Time{1,0,0}) == "00:59:59");
}


TEST_CASE ("format of input")
{
    std::stringstream ss;
    ss << "00:01:00";
    Time t1{};
    ss >> t1;
    CHECK(t1.to_string() == "00:01:00");
}
TEST_CASE ("format of input 2")
{
    std::stringstream ss;
    ss << "00:01:70";
    Time t1{};
    ss >> t1;
    CHECK(ss.fail());
}

TEST_CASE ("comparison operand <")
{
  Time t{12,0,0};
  Time t2{12,13,0};
  CHECK(t < t2);

  Time t3{12,2,0};
  Time t4{14,33,1};
  CHECK_FALSE(t4 < t3);
}

TEST_CASE ("comparison operand >")
{
  Time t{12,0,0};
  Time t2{12,13,0};
  CHECK_FALSE(t > t2  );

  Time t3{12,2,0};
  Time t4{14,33,1};
  CHECK( t4 > t3 );
}

TEST_CASE ("comparison operand <=")
{
  Time t{12,0,0};
  Time t2{12,0,0};
  CHECK(t <= t2  );

  Time t3{12,2,0};
  Time t4{14,33,1};
  CHECK_FALSE( t4 <= t3 );
}

TEST_CASE ("comparison operand >=")
{
  Time t{12,0,0};
  Time t2{12,0,0};
  CHECK(t >=t2  );

  Time t3{12,2,0};
  Time t4{11,33,1};
  CHECK_FALSE( t4 >= t3 );
}

TEST_CASE ("comparison operand ==")
{
  Time t{12,0,0};
  Time t2{12,0,0};
  CHECK(t == t2  );

  Time t3{12,2,0};
  Time t4{14,33,1};
  CHECK_FALSE( t4 == t3 );
}

TEST_CASE ("comparison operand !=")
{
  Time t{12,20,0};
  Time t2{12,0,0};
  CHECK(t != t2  );

  Time t3{12,2,0};
  Time t4{12,2,0};
  CHECK_FALSE( t4 != t3 );
}


// the following line will halt the compilation process. Move it
// one test case at the time and then start creating your own test
// cases
#if 0

#endif
