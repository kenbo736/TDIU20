#include <string>
#include <iostream>
#include <sstream>

#include "catch.hpp"
#include "Time.h"


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
    CHECK( Time{10,10,10}.to_string(true) == "10:10:10 am" );
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
    Time t3{0,0,0};
    CHECK(string(t2+Time{0,0,5}) == "01:02:09");
    CHECK(string(t2+Time{0,0,57}) == "01:03:01");
    CHECK(string(t2+Time{0,58,0}) == "02:00:04");
    CHECK(string(t2+Time{1,59,5}) == "03:01:09");
    CHECK(string(t2+Time{0,58,57}) == "02:01:01");
    CHECK(string(t2+Time{0,57,57}) == "02:00:01");
    CHECK(string(t2+Time{0,56,57}) == "01:59:01");
    CHECK(string(t2+Time{22,57,57}) == "00:00:01");
    CHECK(string(t2+Time{23,57,57}) == "01:00:01");
    CHECK(string(t2+1) == "01:02:05");
    CHECK(string(t2+100) == "01:03:44");
    CHECK(string(t3+172800) == "00:00:00");
    CHECK(string(t3+172802) == "00:00:02");
}

TEST_CASE ("subtraction of a second")
{
    Time t2{2,2,4};
    Time t3{1,5,0};
    CHECK(string(t2-Time{0,0,1}) == "02:02:03");
    CHECK(string(t2-Time{0,0,5}) == "02:01:59");
    CHECK(string(t2-Time{0,3,0}) == "01:59:04");
    CHECK(string(t2-Time{0,3,5}) == "01:58:59");
    CHECK(string(t2-Time{1,3,5}) == "00:58:59");
    CHECK(string(t2-Time{2,3,5}) == "23:58:59");
    CHECK(string(t2-1) == "02:02:03");
    CHECK(string(t3-300) == "01:00:00");
    CHECK(string(t3-3600) == "00:05:00");
    CHECK(string(t3-86400) == "01:05:00");
    CHECK(string(t3-2) == "01:04:58");
    CHECK(string(t3-172800) == "01:05:00");
    CHECK(string(t3-172802) == "01:04:58");
    CHECK(string(t3-259202) == "01:04:58");
}

TEST_CASE ("PRE add of one")
{
    Time t1{2,7,5};
    CHECK(string(++Time{0,58,58}) == "00:58:59");
    CHECK(++Time{0,58,58} == Time{0,58,59});
    CHECK(string(++Time{0,58,59}) == "00:59:00");
    CHECK(++Time{0,58,59} == Time{0,59,0});
    CHECK(string(++Time{0,59,59}) == "01:00:00");
    CHECK(++Time{0,59,59} == Time{1,0,0});
}

TEST_CASE ("POST add of one")
{
    Time t1{2,7,5};
    CHECK(string(Time{0,58,58}++) == "00:58:58");
    CHECK(Time{0,58,58}++ == Time{0,58,58});
    CHECK(string(Time{0,58,59}++) == "00:58:59");
    CHECK(Time{0,58,59}++ == Time{0,58,59});
    CHECK(string(Time{0,59,59}++) == "00:59:59");
    CHECK(Time{0,59,59}++ == Time{0,59,59});
}

TEST_CASE ("PRE remove of one")
{
    CHECK(string(--Time{0,58,58}) == "00:58:57");
    CHECK(--Time{0,58,58} == Time{0,58,57});
    CHECK(string(--Time{0,58,0}) == "00:57:59");
    CHECK(--Time{0,58,0} == Time{0,57,59});
    CHECK(string(--Time{1,0,0}) == "00:59:59");
    CHECK(--Time{1,0,0} == Time{0,59,59});
}

TEST_CASE ("POST remove of one")
{
    CHECK(string(Time{0,58,58}--) == "00:58:58");
    CHECK(Time{0,58,58}-- == Time{0,58,58});
    CHECK(string(Time{0,58,0}--) == "00:58:00");
    CHECK(Time{0,58,0}-- == Time{0,58,0});
    CHECK(string(Time{1,0,0}--) == "01:00:00");
    CHECK(Time{1,0,0}-- == Time{1,0,0});
}

TEST_CASE ("format of input")
{
    std::string test_str{"00:01:00 00:12:12 15:15:15"};
    std::stringstream ss{test_str};

    Time t1{};
    Time t2{};
    Time t3{};
    CHECK_FALSE(ss.eof()); //kollar om vi nått slutet av filen
    ss >> t1 >> t2 >> t3;
    CHECK(t1 == Time{0,1,0});
    CHECK(t2 == Time{0,12,12});
    CHECK(t3 == Time{15,15,15});
    CHECK(ss.str() == test_str); // kollar vad som ligger i strömmen efter
    CHECK(ss.eof()); //kollar om vi nått slutet av filen

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

  Time t5{12,0,0};
  CHECK_FALSE(t < t5);
}

TEST_CASE ("comparison operand >")
{
  Time t{12,0,0};
  Time t2{12,13,0};
  CHECK_FALSE(t > t2);

  Time t3{12,2,0};
  Time t4{14,33,1};
  CHECK( t4 > t3 );

  Time t5{12,0,0};
  CHECK_FALSE(t > t5);
}

TEST_CASE ("comparison operand <=")
{
  Time t{12,0,0};
  Time t2{12,0,0};
  CHECK(t <= t2);

  Time t3{12,2,0};
  Time t4{14,33,1};
  CHECK_FALSE(t4 <= t3);

  Time t5{12,0,0};
  CHECK(t <= t5);
}

TEST_CASE ("comparison operand >=")
{
  Time t{12,0,0};
  Time t2{12,0,0};
  CHECK(t >=t2);

  Time t3{12,2,0};
  Time t4{11,33,1};
  CHECK_FALSE(t4 >= t3);

  Time t5{12,0,0};
  CHECK(t >= t5);
}

TEST_CASE ("comparison operand ==")
{
  Time t{12,0,0};
  Time t2{12,0,0};
  CHECK(t == t2);

  Time t3{12,2,0};
  Time t4{14,33,1};
  CHECK_FALSE(t4 == t3);

  Time t5{12,0,1};
  CHECK_FALSE(t == t5);
  
  Time t6{11,59,59};
  CHECK_FALSE(t6 == t);
}

TEST_CASE ("comparison operand !=")
{
  Time t{12,20,0};
  Time t2{12,0,0};
  CHECK(t != t2);

  Time t3{12,2,0};
  Time t4{12,2,0};
  CHECK_FALSE(t4 != t3);

  Time t5{11,59,59};
  CHECK(t5 != t);
}


// the following line will halt the compilation process. Move it
// one test case at the time and then start creating your own test
// cases
#if 0

#endif
