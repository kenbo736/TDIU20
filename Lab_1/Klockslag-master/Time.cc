#include <iostream>
#include <string>
#include <iomanip>
#include <unistd.h>
#include <sstream>
#include <stdexcept>

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

void Time::constructHelper() const
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

int Time::hour() const
{
  return hh;
}

int Time::minute() const
{
  return mm;
}

int Time::second() const
{
  return ss;
}

bool Time::is_am() const
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

std::string Time::to_string(bool const &am_pm_format) const
{
  std::stringstream inStream;

  std::string am_pm;

  if(is_am() == true)
  {
    am_pm = " am";
  }
  else if(is_am() == false)
  {
    am_pm = " pm";
  }

  inStream << std::setfill('0') << std::setw(2);

  if(am_pm_format == true)
  {
    inStream << hh+calculateOffset();
  }
  else if(am_pm_format == false)
  {
    inStream << hh;
  }

  inStream << ":" << std::setfill('0') << std::setw(2) << mm << 
              ":" << std::setfill('0') << std::setw(2) << ss << std::setw(0);

  if(am_pm_format == true)
  {
    inStream << am_pm;
  }
  else if(am_pm_format == false)
  {
    inStream << "";
  } 

  return inStream.str();
}

int Time::calculateOffset() const
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

std::string string(Time const &ti)
{
  return ti.to_string();
}

std::ostream& operator<<(std::ostream &os, Time const &ti)
{
    os << ti.to_string();
    return os;
}


std::istream& operator>>(std::istream &is, Time &ti)
{
    char c;
    int temp_hh, temp_mm, temp_ss;
    is >> temp_hh >> c >> temp_mm >> c >> temp_ss;

    try
    {
        ti = Time{temp_hh, temp_mm, temp_ss};
    }
    catch(std::exception& e)
    {
      is.setstate(std::ios_base::failbit);
    }
  return is;
}

Time Time::operator+(Time const &rhs) const
{
  Time t3;
  t3.ss = ss + rhs.ss;
  t3.mm = mm + rhs.mm;
  t3.hh = hh + rhs.hh;
  if (t3.ss > 59)
  {
    t3.mm = t3.mm + (t3.ss/60);
    t3.ss = t3.ss % 60;
  }

  if (t3.mm > 59)
  {
    t3.hh = t3.hh + (t3.mm/60);
    t3.mm = t3.mm % 60;
  }

  if (t3.hh > 23)
  {
    t3.hh = t3.hh % 24;
  }
  return t3;
}

Time Time::operator+(int const &rhs) const
{
  Time t3;
  t3.ss = ss + rhs;
  t3.mm = mm;
  t3.hh = hh;
  if (t3.ss > 59)
  {
    t3.mm = t3.mm + (t3.ss/60); 
    t3.ss = t3.ss % 60;
  }

  if (t3.mm > 59)
  {
    t3.hh = t3.hh + (t3.mm/60);
    t3.mm = t3.mm % 60;
  }

  if (t3.hh > 23)
  {
    t3.hh = t3.hh % 24;
  }
  return t3;
}

Time Time::operator-(Time const &rhs) const
{
  Time t3;
  t3.ss = ss - rhs.ss;
  t3.mm = mm - rhs.mm;
  t3.hh = hh - rhs.hh;

  if (t3.ss < 0)
  {
    t3.mm = t3.mm + (t3.ss/60)-1;
    t3.ss = 60 + (t3.ss % 60);
    if (60 + (t3.ss % 60) == 60)
    {
      t3.ss = 0;
      t3.mm = t3.mm+1;
    }
  }

  if (t3.mm < 0)
  {
    t3.hh = t3.hh + (t3.mm/60)-1;
    t3.mm = 60 + (t3.mm % 60);
    if (60 + (t3.mm % 60) == 60)
    {
      t3.mm = 0;
      t3.hh = t3.hh+1;
    }
  }

  if (t3.hh < 0)
  {
    t3.hh = 24 + (t3.hh % 24);
  }

  return t3;
}

Time Time::operator-(int const &rhs) const
{
  Time t3;
  t3.ss = ss - rhs;
  t3.mm = mm;
  t3.hh = hh;

  if (t3.ss < 0)
  {
    t3.mm = t3.mm + (t3.ss/60)-1;
    t3.ss = 60 + (t3.ss % 60);
    if (60 + (t3.ss % 60) == 60)
    {
      t3.ss = 0;
      t3.mm = t3.mm+1;
    }
  }

  if (t3.mm < 0)
  {
    t3.hh = t3.hh + (t3.mm/60)-1;
    t3.mm = 60 + (t3.mm % 60);
    if (60 + (t3.mm % 60) == 60)
    {
      t3.mm = 0;
      t3.hh = t3.hh+1;
    }
  }

  if (t3.hh < 0)
  {
    t3.hh = 24 + (t3.hh % 24);
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

bool Time::operator <(Time const &rhs) const
{
  return(hour() < rhs.hour())
     or (hour() == rhs.hour() && minute() < rhs.minute())
     or (hour()  == rhs.hour() && minute() == rhs.minute() && second() < rhs.second());
}

// Kommentar: Bra �teranv�ndning av operator<!
bool Time::operator >(Time const &rhs) const
{
  return (rhs < *this);
}

bool Time::operator <=(Time const &rhs) const
{
  return !(rhs < *this);
}

bool Time::operator >=(Time const &rhs) const
{
  return !(*this < rhs);
}

bool Time::operator ==(Time const &rhs) const
{
  return !(*this < rhs || rhs < *this);
}

bool Time::operator !=(Time const &rhs) const
{
  return (*this < rhs || rhs < *this);
}
