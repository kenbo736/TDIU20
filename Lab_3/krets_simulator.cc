#include <iostream>
#include <iomanip>
#include "krets_simulator.h"
#include <math.h>

////////////////////////////////// Component //////////////////////////////////////////////////
Component::Component(std::string const &n, Connect &a, Connect &b) : name{n}, link_a{a}, link_b{b}
{}

double Component::get_voltage() const
{
  double volt{};
  if(link_a > link_b)
  {
    volt = link_a - link_b;
  }
  else if(link_a < link_b)
  {
    volt = link_b - link_a;
  }
  return volt; 
}

double Component::get_current() const
{
  return 0;
}

std::string Component::get_name() const
{
  return name;
}

/////////////////////////////////// Battery ////////////////////////////////////////////////////////
Battery::Battery(std::string const &n, double v, Connect &a, Connect &b) : Component{n, a, b}, voltage{v} //konstruktor
{}

void Battery::simulate(double time)
{
  link_a = voltage;
  link_b = 0.0;
}

double Battery::get_current() const
{
  return 0.0;
}

////////////////////////////////// Resistor ///////////////////////////////////////////
Resistor::Resistor(std::string const &n, double r, Connect &a, Connect &b) : Component{n, a, b}, resistance{r}
{}

void Resistor::simulate(double time)
{
  double store{(get_voltage() / resistance) * time};
  if(link_b < link_a)
  {
    link_b = link_b + store;
    link_a = link_a - store;
  }
  else if(link_b > link_a)
  {
    link_a = link_a + store;
    link_b = link_b - store;
  }
}

double Resistor::get_current() const
{
  return get_voltage() / resistance;
}

///////////////////////////////// Capacitor //////////////////////////////////////////
Capacitor::Capacitor(std::string const &n, double c, Connect &a, Connect &b) : Component{n, a, b}, capacitance{c}, charge{}
{}

void Capacitor::simulate(double time)
{
  double store{get_current()*time};
  if(link_b < link_a)
  {
    link_b = link_b + store;
    link_a = link_a - store;
  }
  else if(link_b > link_a)
  {
    link_a = link_a + store;
    link_b = link_b - store;
  }
  charge = charge + store;
}
double Capacitor::get_current() const
{
  return (capacitance * (get_voltage() - charge)); // formeln kan hittas i labbsidan
}

/////////////////////////////////////////////////////////////////////////////////////
void simulate(std::vector<Component*> v, int iterations, int rows, double time)
{
  for(Component* c : v)
  {
    std::cout << std::setw(14) << c->get_name(); // Hämtar namnet
  }
  std::cout << std::endl;


  for(int i=0; i < v.size(); i++)
  {
    std::cout << std::setw(7) << "Volt" << std::setw(7) << "Curr"; // skriver ut volt och strömmen
  }
  std::cout << std::endl;

  for(int i=1; i < iterations+1; i++)
  {
    for(Component* c : v)
    {
      c->simulate(time);
    }
    if(i % (iterations/rows) == 0) // för att välja ut vilka rader som ska skrivas ut
    {
      for (Component* c : v)
      {
        std::cout << std::setprecision(2) << std::fixed << std::setw(7) << c->get_voltage() << std::setw(7) << c->get_current();
      }
      std::cout << std::endl;
    }
  }
  std::cout << std::endl;
}
