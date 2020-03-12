#include "krets_simulator.h"
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

double Component::get_voltage() const
{
    return 0.0;
}

void simulate(vector<Component*> net,int cycles, int writes, double time)
{
    for ( int i{0}; i < (int)net.size(); i++)
    {
	cout << setw(12) << setfill(' ') << net.at(i)->name;
    }
    cout << endl;

    for ( int i{0}; i < (int)net.size(); i++)
    {
	cout << setw(12) << "Volt Curr" ;
    }
    cout << endl;

    for (int a{0}; a < writes; a++)
    {
	cout << "  ";
	for (int c{0}; c < cycles/writes; c++)
	{
	    for( int d{0}; d < (int)net.size(); d++)
	    {
		net.at(d)->simulate(time);
	    }
	}
	for (int b{0}; b < (int)net.size(); b++)
	{
	    cout << setw(5) << fixed << setprecision(2) << net.at(b)->get_voltage() << " ";
	    cout << setw(4) << fixed << setprecision(2) << net.at(b)->get_current() << "  ";
	}
    cout << endl;
    }
}

std::string Component::get_name() const
{
    return std::string();
}

double Resistor::get_current() const
{
    return ((get_voltage())/resistance);
}

double Capacitor::get_current() const
{
    return current;
}

double Battery::get_current() const
{
    return 0;
}

double Resistor::get_voltage() const
{
    return (a.charge - b.charge);
}

double Capacitor::get_voltage() const
{
    return voltage;
}

double Battery::get_voltage() const
{
    return voltage;
}

void Battery::simulate(double)
{
    a.charge = 0;
    b.charge = voltage;
}

void Resistor::simulate(double time)
{
    double temp{b.charge};
    b.charge = (time * ((a.charge - b.charge)/resistance));
    a.charge = (a.charge-b.charge);
    b.charge += temp;
}

void Capacitor::simulate(double time)
{
    double temp_charge{0};
    if (a.charge >= b.charge)
    {
	temp_charge = farad * ((a.charge - b.charge) - voltage) * time;
	b.charge += temp_charge;
	a.charge -= temp_charge;
    }
    else if(a.charge < b.charge)
    {
        temp_charge = farad * ((b.charge - a.charge) - voltage) * time;
	a.charge += temp_charge;
	b.charge -= temp_charge;
    }
    voltage += temp_charge;
}
