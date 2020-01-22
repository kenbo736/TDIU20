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
    int is_am();
    // konstruktor för att bestämma antalet argument
    Time(int h, int m, int s);
    Time(std::string s);
    Time()
    {}

  private:
    int hh{};
    int mm{};
    int ss{};
    void constructHelper()
    {
      if(this->hh > 23 || this->hh < 0)
      {
          throw std::overflow_error("Out of border"); // throws an exception
      }
      else if(this->mm > 59 || this->mm < 0)
      {
          throw std::overflow_error("Out of border");
      }
      else if(this->ss > 59 || this->ss < 0)
      {
          throw std::overflow_error("Out of border");
      }
    }
};

#endif
// Denna fil ska innehålla deklarationer för de typer och funktioner
// som behövs
