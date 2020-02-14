#ifndef TIME_H
#define TIME_H

#include <iostream>
#include <sstream>
#include <algorithm>

class Time {
  public:
    int hour() const;
    int minute() const;
    int second() const;
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

    bool operator<(Time const & rhs) const;
    bool operator>(Time const & rhs) const;
    bool operator==(Time const & rhs) const;
    bool operator!=(Time const & rhs) const;
    bool operator>=(Time const & rhs) const;
    bool operator<=(Time const & rhs) const;

  private:
    int hh{};
    int mm{};
    int ss{};
    void constructHelper();
    int calculateOffset();
};

std::ostream& operator<<(std::ostream &os, const Time &ti);
std::istream& operator>>(std::istream &is, Time &ti);

std::string string(Time ti);
#endif
// Denna fil ska innehålla deklarationer för de typer och funktioner
// som behövs
