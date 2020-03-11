#include "krets_simulator.h"
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

void Batteri::simulate(double)
{
  a.potential = volt;
  b.potential = 0.0;
}

double Batteri::current()
{
  return 0.0;
}

double Batteri::voltage()
{
  return volt;
}

void Capacitor::simulate(double time)
{
  double charge = current()*time;
  if (a.potential > b.potential)
    {
      stored_charge = stored_charge + charge;
      a.potential = a.potential - charge;
      b.potential = b.potential + charge;
    }
  else
    {
      stored_charge = stored_charge + charge;
      b.potential = b.potential - charge;
      a.potential = a.potential + charge;
    }
}

double Capacitor::voltage()
{
  if (a.potential > b.potential)
    return (a.potential - b.potential);
  else
    return (b.potential - a.potential);
}
double Capacitor::current()
{
  return (capacitance*(voltage() - stored_charge));
}


void Resistor::simulate(double time)
{
  if (a.potential < b.potential)
    {
      b.potential = b.potential - (voltage()/resistance)*time;
      a.potential = a.potential + (voltage()/resistance)*time;
    }
  else
    {
      a.potential = a.potential - (voltage()/resistance)*time;
      b.potential = b.potential + (voltage()/resistance)*time;
    }
}
double Resistor::voltage()
{
  if (a.potential > b.potential)
    return (a.potential - b.potential);
  else
    return (b.potential - a.potential);
}
double Resistor::current()
{
  return (voltage()/resistance);
}

void simulate(int iterations, int printouts, double dt, vector<Component*> komp )
{

    for (Component* c : komp)
    {
        cout << setw(12) << c -> get_name();
    }
    cout<<endl;
    for (unsigned int v{}; v < komp.size();v++)
    {
        cout << setw(6) <<  "volt" << setw(6) << "curr";

    }
    int x= iterations/printouts;
    cout << endl;

    for (int i{}; i < printouts;i++)
    {
        for (int j{}; j < x ;j++)
	{
            for (Component* c : komp)
	    {
                c -> simulate(dt);
	    }

	}
        for (Component* k : komp)
	{
            k -> print(cout);
	}
        cout << endl;
    }
}

void Component::print(std::ostream& os)
{
  os << setprecision(2) << fixed << setw(6) << voltage() << setw(6) << current();
}

string Component::get_name()
{
    return name;
}

void memoryfix (std::vector<Component*> v)
{
  for (auto i : v)
  {
    delete i;
  }
  v.clear();
}
