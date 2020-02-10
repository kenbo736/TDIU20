#ifndef TIME_H
#define TIME_H

#include <iostream>
#include <sstream>
#include <algorithm>

class Time {
  public:
    int hour();
    int minute();
    int second();
    bool is_am();
    std::string to_string(bool am_pm_format = false);

    Time(int h, int m, int s); // konstruktor för att bestämma antalet argument
    Time(std::string s);
    Time()
    {}

    Time operator+(const Time &rhs) const;
    Time operator-(const Time &rhs) const;
    Time& operator++();
    Time operator++(int);
    Time& operator--();
    Time operator--(int);

    friend std::ostream& operator<<(std::ostream &os, const Time &ti);
    friend std::istream& operator>>(std::istream &is, Time &ti);

    friend bool operator<(Time const & lhs, Time const & rhs);
    friend bool operator>(Time const & lhs, Time const & rhs);
    friend bool operator==(Time const & lhs, Time const & rhs);
    friend bool operator!=(Time const & lhs, Time const & rhs);
    friend bool operator>=(Time const & lhs, Time const & rhs);
    friend bool operator<=(Time const & lhs, Time const & rhs);
    
  private:
    int hh{};
    int mm{};
    int ss{};
    void constructHelper();
    int calculateOffset();
};

std::string string(Time ti);
#endif
// Denna fil ska innehålla deklarationer för de typer och funktioner
// som behövs
