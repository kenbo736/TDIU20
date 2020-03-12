#ifndef KRETS_SIMULATOR_H
#define KRETS_SIMULATOR_H
#include <iostream>
#include <vector>

class Connection
{
public:
    double charge = 0;
};


class Component
{
public:
    virtual double get_voltage() const = 0;
    virtual double get_current() const = 0;
    virtual void simulate(double time) = 0;
    std::string name;
protected:
    Connection &a;
    Connection &b;
public:
    Component(std::string const & new_name, Connection & n, Connection & p)
	:  name{ new_name }, a{ n }, b{ p } {};
    std::string get_name() const;
    virtual ~Component() = default;
};


class Battery : public Component
{
public:
    Battery(std::string name, double voltage, Connection & n, Connection & p)
	: Component{ name, n, p }, voltage{ voltage } {};
    double get_current() const override;
    double get_voltage() const override;
    void simulate(double)  override;
private:
    double voltage;
};


class Resistor : public Component
{
public:
    Resistor(std::string name, double resistance, Connection & n, Connection & p)
	: Component{ name, n, p }, resistance{ resistance } {};
    double get_current() const override;
    double get_voltage() const override;
    void simulate(double) override;
private:
    double resistance;
};


class Capacitor : public Component
{
public:
    Capacitor( std::string name, double farad, Connection & n, Connection & p)
	: Component{ name, n, p }, farad{ farad} {};
    double get_current() const override;
    double get_voltage() const override;
    void simulate(double) override;
private:
    double farad{0},voltage{0},current{0};
};

void simulate(std::vector<Component*> net,int cycles, int writes, double time);

#endif
