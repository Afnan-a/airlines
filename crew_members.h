#ifndef CREW_MEMBERS_H
#define CREW_MEMBERS_H

#include <vector>
#include <iostream>
#include "crew_member.h"
using namespace std;


class crews{
private:
       int ccount;
     vector <crew*> crewvec;
      // crewvec crewlist;
public:
 //       crews();
        void storecrew();
        void loadcrew();
        void add_crew();
        void delete_crew();
        void edit_crew();
        crew* search_crew(string);
        vector <crew*> get_crewlist();
        void print_all_crew();
        void print_entity_crew();
};

#endif