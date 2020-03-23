#include <iostream>
#include <iomanip>
#include <vector>
#include "krets_simulator.h"
#include <sstream>
#include <stdexcept>

int main(int argc, char* argv[])
{
  if(argc == 5) // 5 argument
  {
      int iterations{};
      int rows{};
      double time{};
      double volt{};
    try
    {
      iterations = std::stoi(argv[1]);
      rows = std::stoi(argv[2]);
      time = std::stod(argv[3]);
      volt = std::stod(argv[4]);
    }
    catch(std::invalid_argument& e)
    {
      std::cerr << "invalid argument" << std::endl;
      exit(0);
    }

    // 1
    Connect p{}, n{}, x{}, y{}, l{}, r{};
    std::vector<Component*> net;
    net.push_back(new Battery("Bat", volt, p, n));
    net.push_back(new Resistor("Res1", 6.0, p, y));
    net.push_back(new Resistor("Res2", 4.0, x, y));
    net.push_back(new Resistor("Res3", 8.0, n, x));
    net.push_back(new Resistor("Res4", 12.0, n, y));
    simulate(net, iterations, rows, time);

    for(Component* c : net)
    {
      delete c; //tar bort objekten för att ge tillbaka minne 
    }
    net.clear();
    // 2
    net.push_back(new Battery("Bat", volt, p, n));
    net.push_back(new Resistor("Res1", 150.0, p, l));
    net.push_back(new Resistor("Res2", 50.0, p, r));
    net.push_back(new Resistor("Res3", 100.0, l, r));
    net.push_back(new Resistor("Res4", 300.0, n, l));
    net.push_back(new Resistor("Res5", 250.0, r, n));
    simulate(net, iterations, rows, time);

    for(Component* c : net)
    {
      delete c; //tar bort objekten för att ge tillbaka minne 
    }
    net.clear();
    // 3
    net.push_back(new Battery("Bat", volt, p, n));
    net.push_back(new Resistor("Res1", 150.0, l, p));
    net.push_back(new Resistor("Res2", 50.0, p, r));
    net.push_back(new Capacitor("Cap3", 1.0, l, r));
    net.push_back(new Resistor("Res4", 300.0, l, n));
    net.push_back(new Capacitor("Cap5", 0.75, n, r));
    simulate(net, iterations, rows, time);
    
    for(Component* c : net)
    {
      delete c; //tar bort objekten för att ge tillbaka minne 
    }
    
  }
  else
  {
    std::cerr << "Too few arguments" << std::endl;
  }
  return 0;
}