#ifndef KRETS_SIMULATOR_H
#define KRETS_SIMULATOR_H
#include <iostream>
#include <string>
#include <vector>




class Connection
{
 public:
    double potential;
};

class Component
{

 protected:
    std::string name;
    Connection& a;
    Connection& b;


 public:
  virtual void simulate(double) = 0;
  virtual double voltage()  = 0;
  virtual double current()  = 0;
  void print(std::ostream& os) ;
  std::string get_name(); void simulate(int iterations, int printouts, double dt, std::vector<Component*> komp);

  Component(std::string n, Connection& x, Connection& y)
     :name(n), a(x), b(y) {}

 virtual ~Component() {}

};
void simulate(int iterations, int printouts, double dt, std::vector<Component*> komp);
class Resistor : public Component
{
 private:
  double resistance;

 public:
    void simulate(double time) override;
     double voltage() override;
    double current() override;

 Resistor(std::string name, Connection& a, Connection& b, double resistance)
   : Component(name, a, b), resistance(resistance) {}
};


class Batteri: public Component
{
 private:
  double volt;

 public:
  void simulate (double) override;
  double voltage()  override;
  double current() override;

 Batteri(std::string name, Connection& a, Connection& b, double volt)
   : Component(name, a, b), volt(volt){}

};

class Capacitor : public Component
{ private:
  double capacitance;
  double stored_charge;

 public:
  void simulate(double time) override;
  double voltage() override;
  double current() override;

 Capacitor(std::string name, Connection& a, Connection& b, double capacitance)
   : Component(name, a, b), capacitance(capacitance), stored_charge(0) {}
};
void memoryfix (std::vector<Component*> v);
#endif
