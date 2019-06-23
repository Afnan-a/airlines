#ifndef FLIGHT_H
#define FLIGHT_H

#include <vector>
#include <string>
#include <list>
#include <iostream>
#include <cstring>
#include <ctime>
#include <cstdio>

 using namespace std;
#include "crew_member.h"
#include "plane.h"
#include "crew_members.h"
#include "planes.h"

class flight
{
private:
        plane planeobj;
        planes planesobj;
        crews *crewsobj;
	char  *plane_id ;   //(tail Number)
//	int flight_number;
	int n_pilots, n_coPilot; // the number of pilots (flights over 8hrs require 2 pilots + 2 co-pilots)
	int n_crew;  // number of cabin crew  (flights over 8hrs require rqr double mini)
	vector <string> cabin_ids;		//list of cabin crew IDs
	vector <string> pilot_ids;
        vector <string> copilot_ids;			// list of pilots IDs
	time_t start_date; //date or time (in GMT)
	time_t end_date; 
	char *sairport_code; 	//starting airport code 3 letters
        char *eairport_code;  //ending airport code 3 letters
	int people; 	//number of passengers
	string status;
//	char status[3][10]={"Active","Complete","Cancelled"};
public:
	flight();
        flight(char id[], int n1,int n2, time_t st, time_t e, char sc[], char ec[], int p, vector <string> pi ,vector <string> cpi, vector <string> cab, string stat);

        void prints(); //print starting time
        void printe(); //print end time
        
        void set_pilots ();
         vector <string> get_pilots();
        void printpi();

        void set_cpilots ();
         vector <string> get_cpilots();
        void printcpi();

        void set_cab ();
        vector<string> get_cab();
        void printcab();


        void set_startdate();
        time_t get_startdate();

        void set_enddate();
        time_t get_enddate();

	void set_plane_id ();
	char* get_plane_id () const;
	
	void set_n_pilots();
	int get_n_pilots()const;

	void set_n_crew();
	int get_n_crew()const;

	void set_sairport_code();
	char* get_sairport_code()const;

	void set_eairport_code();	
	char* get_eairport_code()const;

	void set_people();
	int get_people()const;

	void set_status ();
	string get_status()const;
};	 
#endif

