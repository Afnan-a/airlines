#ifndef FLIGHTS_H
#define FLIGHTS_H

#include <string>
#include <vector>
#include <iostream>
using  namespace std;
#include "flight.h"


class flights {

private:
        int fcount;
        vector<flight*> vecflights;

public: 
        void loadflight();
        void storeflight();

	void addFlight();
	void edit_Flight();
	void deleteFlight();
	flight* findFlight();

        // find available pi/crew
	void print_enteries(); // prints all enteries in the collection
	void print_oneEntity (); // prints details of one entity
	void printPlanFlights (); // prints the flights with specific plane
	void print_crew_flights();  // prints all flights with specific crew
};

#endif
