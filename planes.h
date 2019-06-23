#ifndef PLANES_H
#define PLANES_H

#include <vector>
#include <iostream>
#include "plane.h"
using namespace std;

class planes{
private:
        int pcount;
        vector <plane*> vecplane;
     //   plane* plane1;
public:
   //     planes();

        void storeplane();
        void loadplane();

        void add_plane();
        void delete_plane ();
        void edit_plane ();
        plane* search_plane(char*);
        void print_all_planes();
        void print_entity();    //print for single entity
};

#endif