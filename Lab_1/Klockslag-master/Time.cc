#include <iostream>
#include <string>
#include <iomanip>
#include <unistd.h>
#include <sstream>

#include "Time.h"

Time::Time(std::string s)
{
  std::replace(s.begin(), s.end(), ':', ' ');
  std::stringstream timestream{s};
  timestream >> this->hh >> this->mm >> this->ss;
  constructHelper();
}

Time::Time(int h, int m, int s) : hh(h), mm(m), ss(s) //member initializer list
{
  constructHelper();
}

void Time::constructHelper()
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

int Time::hour()
{
  return hh;
}

int Time::minute()
{
  return mm;
} 

int Time::second()
{
  return ss;
}

bool Time::is_am()
{
  if(hh > 11)
  {
    return false;
  }
  else
  {
    return true;
  }
}

std::string Time::to_string(bool am_pm_format)
{
  std::stringstream inStream; 
  std::string am_pm {is_am() ? " am" : " pm"}; //shorthand if!
  //int offset{calculateOffset()};

  inStream << std::setfill('0') << std::setw(2) << hh+(am_pm_format ? calculateOffset() : 0) << ":" 
           << std::setfill('0') << std::setw(2) << mm << ":" << std::setfill('0') << std::setw(2) 
           << ss << std::setw(0) << (am_pm_format ? am_pm : "");
  
  return inStream.str();
}

int Time::calculateOffset()
{
  if(hh == 0)
  {
    return 12;
  }
  else if(hh >= 1 && hh <= 12)
  {
    return 0;
  }
  else
  {
    return -12;
  }
}

std::string string(Time ti)
{
  return ti.to_string();
}

std::ostream& operator<<(std::ostream& os, const Time& ti)
{
    os << std::setfill('0') << std::setw(2) << ti.hh << ':' 
       << std::setfill('0') << std::setw(2) << ti.mm << ':' 
       << std::setfill('0') << std::setw(2) << ti.ss;
    return os;
}

Time Time::operator+(const Time &rhs) const
{ 
  Time t3;
  t3.ss = ss + rhs.ss;
  t3.mm = mm + rhs.mm;
  t3.hh = hh + rhs.hh;
  if (t3.ss > 59)
  {
    t3.mm = t3.mm + 1;
    t3.ss = t3.ss % 60;
  }

  if (t3.mm > 59)
  {
    t3.hh = t3.hh + 1;
    t3.mm = t3.mm % 60;
  }
  
  if (t3.hh > 23)
  {
    t3.hh = 0;
    t3.mm = 0;
    t3.ss = 0;
  }
  return t3; 
}

Time Time::operator-(const Time &rhs) const
{ 
  Time t3;
  t3.ss = ss - rhs.ss;
  t3.mm = mm - rhs.mm;
  t3.hh = hh - rhs.hh;
  if (t3.ss < 0)
  {
    t3.mm = t3.mm - 1;
    t3.ss = 60 + (t3.ss % 60);
  }

  if (t3.mm < 0)
  {
    t3.hh = t3.hh - 1;
    t3.mm = 60 + (t3.mm % 60);
  }
  
  if (t3.hh > 23)
  {
    t3.hh = 0;
    t3.mm = 0;
    t3.ss = 0;
  }
  return t3; 
}

Time& Time::operator++()
{
  *this = *this + Time{0,0,1};
  return *this; 
}

Time Time::operator++(int)
{
  Time temp = *this;
  ++*this;
  return temp;
}

Time& Time::operator--()
{
  *this = *this - Time{0,0,1};
  return *this; 
}

Time Time::operator--(int)
{
  Time temp = *this;
  --*this;
  return temp;
}
// I denna fil läggs definitionerna (implementationen) av de funktioner
// som deklarerats i Time.h
