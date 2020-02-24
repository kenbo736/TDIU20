#ifndef TIME_H
#define TIME_H

#include <iostream>
#include <sstream>
#include <algorithm>

// TODO: Alla ickeprimitiva parametrar som inte ska �ndras ska vara
// const&.

// TODO: Alla funktioner som inte ska �ndra p� "this"-objektet ska
// vara const.

class Time {
  public:
    int hour() const;
    int minute() const;
    int second() const;
    bool is_am() const;
    std::string to_string(bool const &am_pm_format = false) const;

    Time(int h, int m, int s); // konstruktor för att bestämma antalet argument
    Time(std::string s);
    Time()
    {}

    Time operator+(Time const &rhs) const;
    Time operator+(int const &rhs) const;
    Time operator-(Time const &rhs) const;
    Time operator-(int const &rhs) const;
    Time& operator++();
    Time operator++(int);
    Time& operator--();
    Time operator--(int);

    bool operator<(Time const  &rhs) const;
    bool operator>(Time const &rhs) const;
    bool operator==(Time const &rhs) const;
    bool operator!=(Time const &rhs) const;
    bool operator>=(Time const &rhs) const;
    bool operator<=(Time const &rhs) const;

  private:
    int hh{};
    int mm{};
    int ss{};
    void constructHelper() const;
    int calculateOffset() const;
};

std::ostream& operator<<(std::ostream &os, Time const &ti);
std::istream& operator>>(std::istream &is, Time &ti);

std::string string(Time const &ti);
#endif
// Denna fil ska innehålla deklarationer för de typer och funktioner
// som behövs
