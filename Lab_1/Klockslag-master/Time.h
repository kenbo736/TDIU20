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
    // konstruktor för att bestämma antalet argument
    Time(int h, int m, int s);
    Time(std::string s);
    Time()
    {}
    friend std::ostream& operator<<(std::ostream &os, const Time &ti); //fråga om friend
    Time operator+(Time const &t1) const; //const igen????

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
