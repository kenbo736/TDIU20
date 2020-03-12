#include <iostream>
#include <vector>
#include "krets_simulator.h"
#include <stdlib.h>
#include <errno.h>   // for errno
#include <limits.h>  // for INT_MAX

using namespace std;

int main(int argc, char* argv[])
{
    int cycles, writes, volt;
    double time;

    if (argc < 5)
    {
	throw invalid_argument("Saknar rätt antal inmatningar");
    }
    else if (argc > 5)
    {
	throw invalid_argument("För många inmatningar");
    }

    char *endptr, *str;
    long val;

    for (int i{1}; i != argc; i++)
    {
	str = argv[i];
	val = strtol(str, &endptr, 10);

	if (endptr == str)
	{
	    throw invalid_argument("Error, missing digit.");
	}
    }

    cout << endl;
    cycles = atoi(argv[1]);
    cout << "Cycles: " << cycles << ", ";

    writes = atoi(argv[2]);
    cout << "Writes: " << writes << ", ";

    time = atof(argv[3]);
    cout << "Time: " << time << ", ";

    volt = atoi(argv[4]);
    cout << "Volt: " << volt << endl << endl;;

    Connection n, p, Q124, Q23;
    vector<Component*> net;
    net.push_back(new Battery("Bat", volt, n, p));
    net.push_back(new Resistor("R1", 6.0, p, Q124));
    net.push_back(new Resistor("R2", 4.0, Q124, Q23));
    net.push_back(new Resistor("R3", 8.0, Q23, n));
    net.push_back(new Resistor("R4", 12.0, Q124, n));
    cout << "  Krets 1: " << endl;
    simulate(net, cycles, writes, time);

    net.clear();
    cout << "  ______________________________________________________________________";
    cout << endl;
    Connection n1,p1,l,r;
    net.push_back(new Battery("Bat", volt, n1, p1));
    net.push_back(new Resistor("R1", 150.0, p1, l));
    net.push_back(new Resistor("R2", 50.0, p1, r));
    net.push_back(new Resistor("R3", 100.0, r, l));
    net.push_back(new Resistor("R4", 300.0, l, n1));
    net.push_back(new Resistor("R5", 250.0, r, n1));
    cout << "  Krets 2: " << endl;
    simulate(net, cycles, writes, time);
    net.clear();
    cout << "  ______________________________________________________________________";
    cout << endl;
    Connection n2,p2,l1,r1;
    net.push_back(new Battery("Bat", volt, n2, p2));
    net.push_back(new Resistor("R1", 150.0, p2, l1));
    net.push_back(new Resistor("R2", 50.0, p2, r1));
    net.push_back(new Capacitor("C3", 1.0, r1, l1));
    net.push_back(new Resistor("R4", 300.0, l1, n2));
    net.push_back(new Capacitor("C5", 0.5, r1, n2));
    cout << "  Krets 3: " << endl;
    simulate(net, cycles, writes, time);
    return 0;
}
