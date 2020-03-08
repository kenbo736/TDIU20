#ifndef KRETS_SIMULATOR_H
#define KRETS_SIMULATOR_H

#include <iostream>

class Connect
{
public:
  double voltage{};
};

class Component // består av connection
{
public:
  virtual double get_current() = 0;
  virtual void simulate() = 0;

protected:
  virtual char a{};
  virtual char b{};

};

class Battery : public Component
{
private:

};

class Resistor : public Component
{

};

class Capacitor : public Component
{

};

void simulate();

#endif
