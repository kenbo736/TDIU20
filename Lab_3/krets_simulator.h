#ifndef KRETS_SIMULATOR_H
#define KRETS_SIMULATOR_H

#include <iostream>
#include <vector>

using Connect = double;


//////////////////////////////////////////////////////////////////////////

class Component // man får se component mer som en abstract klass som
{
public:
  Component(std::string const &name, Connect &a, Connect &b); //default
  virtual ~Component() = default;
  double get_voltage() const; // virtual om det är olika functioner
  virtual double get_current() const = 0; // pure virtual
  std::string get_name() const;
  virtual void simulate(double time) = 0; // simulate måste finnas i de classer som äver från component // pure virtual

protected:
  Connect& link_a;
  Connect& link_b; 
  std::string name;
};

////////////////////////////////////////////////////////////////////////

class Battery : public Component // battery ska ärva delar från component 
{
public:
  Battery(std::string const &name, double v, Connect &a, Connect &b); // konstructor
  void simulate(double time) override;
  double get_current() const override;

private:
  double voltage;
};

//////////////////////////////////////////////////////////////////////

class Resistor : public Component
{
public:
  Resistor(std::string const &name, double r, Connect &a, Connect &b);
  void simulate(double time) override;
  double get_current() const override;

private:
  double resistance;
};

//////////////////////////////////////////////////////////////////

class Capacitor : public Component
{
public: 
  Capacitor(std::string const &name, double c, Connect &a, Connect &b);
  void simulate(double time) override;
  double get_current() const override;

private:
  double capacitance;
  double charge;
};

void simulate(std::vector<Component*> array, int iterations, int rows, double time);
#endif
