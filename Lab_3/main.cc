#include "krets_simulator.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;
int main(int argc, char* argv[])
{
    if(argc!=5)
    {
        cerr<<"För få inmatningar";
        return 1;
    }

    int iterations{};
    int printouts{};
    double dt{};
    try{
        iterations = stoi(argv[1]);
        printouts = stoi(argv[2]);
        dt=stod(argv[3]);
    }catch(invalid_argument &)
    {
        cerr<<"Fel inmatning";
        return 1;
    }

  Connection N{}, P{}, Q124{}, Q23{};
  vector<Component*> c{};
  c.push_back(new Batteri{"Bat", N, P, 24.0});
  c.push_back(new Resistor{"R1", P, Q124, 6.0});
  c.push_back(new Resistor{"R2", Q124, Q23, 4.0});
  c.push_back(new Resistor{"R3", Q23, N, 8.0});
  c.push_back(new Resistor{"R4", Q124, N, 12.0});
  simulate(iterations, printouts, dt, c);
  memoryfix(c);

  Connection N2{}, P2{}, R{}, L{};
  vector<Component*> c2{};
  c2.push_back(new Batteri{"Bat", N2, P2, 24.0});
  c2.push_back(new Resistor{"R1", P2, L, 150.0});
  c2.push_back(new Resistor{"R2", P2, R, 50.0});
  c2.push_back(new Resistor{"R3", R, L, 100.0});
  c2.push_back(new Resistor{"R4", L, N2, 300.0});
  c2.push_back(new Resistor{"R5", R, N2, 250.0});
  simulate(iterations,printouts, dt, c2);
  memoryfix(c2);


  Connection P3{},N3{},L3{},R3{};
  vector<Component*> c3{};
  c3.push_back(new Batteri{"Bat", N3, P3, 24.0});
  c3.push_back(new Resistor{"R1", P3, L3, 150.0});
  c3.push_back(new Resistor{"R2", P3, R3, 50.0});
  c3.push_back(new Resistor{"C3", R3, L3, 1.0});
  c3.push_back(new Resistor{"R4", N3, L3,  300.0});
  c3.push_back(new Resistor{"C5",N3, R3 ,0.75});
  simulate(iterations,printouts, dt, c3);
  memoryfix(c3);
}
