#include <iostream>
#include <string>
#include <iomanip>
#include <unistd.h>

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

int Time::is_am()
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
// I denna fil läggs definitionerna (implementationen) av de funktioner
// som deklarerats i Time.h
