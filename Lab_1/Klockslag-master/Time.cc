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
           << std::setfill('0') << std::setw(2) << mm << ":" << std::setfill('0') << std::setw(2) << ss << std::setw(0) << (am_pm_format ? am_pm : "");
  
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
// I denna fil läggs definitionerna (implementationen) av de funktioner
// som deklarerats i Time.h
