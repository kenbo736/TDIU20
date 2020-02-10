#ifndef TIME_H
#define TIME_H

#include <iostream>
#include <sstream>
#include <algorithm>

// detta är en kommentar

class Time {
  public:
    //void set_hour();
    //void set_minute();
    //void set_second();
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
    friend std::istream& operator>>(std::istream &is, Time &ti);
    Time operator+(const Time &rhs) const;
    Time operator-(const Time &rhs) const;
    Time& operator++();
    Time operator++(int);
    Time& operator--();
    Time operator--(int);
    

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
