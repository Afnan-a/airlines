#include <iostream>
#include <ctime>

using namespace std;

#include "flight.h"
#include "Flights.h"
#include "plane.h"
#include "planes.h"
#include "crew_member.h"
#include "crew_members.h"

crews c;
planes p;
flights f;

int main (){

        cout <<"CSCE 1040       Afnan ALkhamis   afnanalkhamis@myunt.edu        HW #4\n\n";


        int option =1 , id =0;

        cout <<"What do you want to do\n";

        while (option != 0){
                cout << "Please choose from below:\n"
                <<"  0-  quite\n  1- Add plane\n  2- Add crew member\n  3- Add flight\n"
                <<"  4- Edit plane\n  5- Edit crew member\n  6- Edit flight\n"
                <<"  7- Delete plane\n  8- Delete crew member\n  9- Delete flight\n"
                <<" 10- Print planes\n 11- Showe data about a plane"
                <<" 12- Print crew members\n 13- Showe data about a crew member\n"
                <<" 14- print flights\n 15- Showe data about a flight\n"
                <<" 16- Print schedule of a plane\n 17- Print schedule of a crew member\n";
                cin >>option; cin.ignore();
                switch (option)
                {
                case 0:
                        cout <<"QUITE\n";
                        break;
                case 1: p.add_plane();
                        break;
                case 2: c.add_crew();
                        break;
                case 3: f.addFlight();
                        break;
                case 4: p.edit_plane();
                        break;
                case 5: c.edit_crew();
                        break;
                case 6: f.edit_Flight();
                        break;

                case 7: p.delete_plane();
                        break;
                case 8: c.delete_crew();
                        break;
                case 9: f.deleteFlight();
                        break;
                case 10: p.print_all_planes();
                        break;
                case 11: p.print_entity();
                        break;
                case 12: c.print_all_crew();
                        break;
                case 13: c.print_entity_crew();
                        break;
                case 14: f.print_enteries();
                        break;
                case 15: f.print_oneEntity();
                        break;
                case 16: f.printPlanFlights();
                        break;
              /*   case 17: f.print_crew_flights();
                        break; */
                default:
                cout <<"That was invalid option\n";
                        break;
                }
        }
        return 0;
}