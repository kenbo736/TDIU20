#ifndef KRETS_SIMULATOR_H
#define KRETS_SIMULATOR_H

#include <iostream>

class Connect
{
public:
  double voltage{};
  double get_voltage();
  void set_voltage();

};

class Component // bas klassen
{
public:
  Component(); //default
  Component(std::string name, C);
  virtual double get_current() = 0;
  virtual void simulate() = 0;
  double get_voltage();

protected:
  virtual Connect a{};
  virtual Connect b{};

};

class Battery : public Component
{
public:
  void simulate();

private:
  double voltage{};

};

/*class Resistor : public Component
{
public:
  double get_current() override;
};

class Capacitor : public Component
{

};*/

void simulate();

#endif
