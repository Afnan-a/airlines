#include <iostream>
#include <string>
#include <iterator>
#include <fstream>
#include <cstdlib>

using namespace std;

#include "Flights.h"
#include "crew_member.h"
#include "plane.h"
#include "crew_members.h"
#include "planes.h"
#include <ctime>

extern crews c;
extern planes p;


void flights::storeflight()
{
    ofstream fout;
    fout.open("flights.dat");
    fout << vecflights.size() << endl;
    
    flight *temp;
    vector<flight*>::iterator it;
    for ( it = vecflights.begin(); it != vecflights.end(); ++it)
    {
        temp = *it;
        fout << temp->get_plane_id() << " " << temp->get_n_crew() << " " << temp->get_n_pilots() 
         << " " << temp->get_startdate()  << " " << temp->get_enddate()  << " " << temp->get_sairport_code()
         << " "<<temp->get_eairport_code()<< " " <<temp->get_status()
         <<endl;
    }
    fout.close();
}

void flights::loadflight()
{
    ifstream fcin;
        flight *temp;
        flight t;
        char* pid; //plane ID number
        int n1, n2, p; // n1 number of crew, n2 number of pilots or co-pilots
        time_t st, e; // st starting time , e ending time
        char *sc, *ec; //sc starting code of airport, ec ending
        vector <string> pi ; 
        vector <string> cpi;
         vector <string> cab;
         string stat;
  
    fcin.open("flights.dat");
    fcin >> fcount; fcin.ignore();
    
    for (int i = 0; i <  fcount ; i++)
    {
        fcin >> pid >> n1 >> n2 >> st >> e >> sc >> ec >> p  ;
         vecflights.push_back(new flight(pid,n1, n2, st,e,sc,ec,p,pi,cpi,cab,stat));
    }

    fcin.close();
    
}


void flights::addFlight(){
        flight *temp;
        flight t;
        char pid[20]; //plane ID number
        int n1, n2, p;
        time_t st, e;
        char sc[4], ec[4];
        vector <string> pi ;
        vector <string> cpi;
         vector <string> cab;
         string stat ;

        crew obj1;

         cout << "Enter the tail number of the plane to be used for this flight: \n";
         cin.getline(pid,20);

         cout <<"Enter the first 3 LETTERS of the airport code: \n";
         cin.getline(sc,4);
        cout <<"Enter the last 3 LETTERS of the airport code: \n";
        cin.getline(ec,4);
                  cout << "Enter number of passengers: \n";
                  cin >>p; cin.ignore();

          struct tm stime;
  
                int year;
                int month ;
                int day ;
                int hour;
                int min ;  
                               cout <<endl<<"Enter The starting date month/day/year :\n";
               scanf("%d/%d/%d",&month,&day,&year);
                
               cout <<endl<<"Enter The starting time Hours:Minutes :\n";
               scanf("%d:%d",&hour,&min);

                stime.tm_year = year-1900; 
                stime.tm_mon = month-1;
                stime.tm_mday = day;
                stime.tm_hour = hour;
                stime.tm_min = min;
                stime.tm_sec = 0;

                 st = mktime(&stime);
                const struct tm *when = gmtime(&st); 
        
         struct tm stimee;
  
                int year1;
                int month1 ;
                int day1 ;
                int hour1;
                int min1 ;
                int sec1 = 0; 

               cout <<endl<<"Enter The ending date month/day/year :\n";
               scanf("%d/%d/%d",&month1,&day1,&year1);
                
               cout <<endl<<"Enter The ending time Hours:Minutes :\n";
               scanf("%d:%d",&hour1,&min1);

                stime.tm_year = year1-1900; 
                stime.tm_mon = month1-1;
                stime.tm_mday = day1;
                stime.tm_hour = hour1;
                stime.tm_min = min1;
                stime.tm_sec = sec1;

                 e = mktime(&stimee);
                 const struct tm *whenn = gmtime(&e);
                n2 = 2;n1=3;
        int i =0; string id;
        cin.ignore();
        while(i<n2){
                cout <<"Please Enter pilot's #"<<i+1<<" ID:\n";
                getline(cin,id);
                pi.push_back(id);
                cout <<"Please Enter Co-pilot's #"<<i+1<<" ID:\n";
                 getline(cin,id);
                cpi.push_back(id);
                i++;
        }
        i=0;
        while(i<n1){
                cout <<"Please Enter cabin's #"<<i+1<<" ID:\n";
                getline(cin,id);
                cab.push_back(id);
                i++;
        }

      /*   temp->set_plane_id();
        pid = temp->get_plane_id(); 

        temp->set_sairport_code();
        sc = temp->get_sairport_code();

        temp->set_eairport_code();
        ec = temp->get_eairport_code();

        temp->set_people();
        p = temp->get_people();
        
        temp->set_startdate();
        st = temp->get_startdate();

        temp->set_enddate();
        e = temp->get_enddate();

        temp->set_n_crew();
        n1 = temp->get_n_crew();

        temp->set_n_pilots();
        n2 = temp->get_n_pilots();

        temp->set_pilots();
        pi = temp->get_pilots();

        temp->set_cpilots();
        cpi = temp->get_cpilots();

        temp->set_cab();
        cab = temp->get_cab(); */

        stat ="Active";
        
        temp = new flight(pid,n1, n2, st,e,sc,ec,p,pi,cpi,cab, stat);
        
        vecflights.push_back(temp);
        
}

void flights::edit_Flight(){
        /* int c; //choice
        string id;
        cout <<"Enter the tail number of the flight:\n";
        getline(cin,id);


        cout <<"Choose to change the statuse of the flight to be :\n"
        <<"1- Completed\n"<<"2- Cancalled\n";
        cin >> c; cin.ignore();
        flight f;
        if(c ==1){
                findFlight()->set_status()
        }*/

         findFlight()->set_status();
}
void flights::deleteFlight(){
        string x; int c; //choice
        unsigned int i;
        bool found = false;
        cout <<"Deleting flight\n";
        cout <<"Choose from below:\n"
        <<"1- Delete specific flight\n"<<"2- Delete All cancelled flights\n"
        <<"3- Delete All completed flights\n";
        cin >>c; cin.ignore();
        if (c == 1){
                cout <<"Please Enter the tail number of the flight\n";
                getline(cin,x); 

                vector<flight*>::iterator it;
                i =0;
                for(it = vecflights.begin(); it != vecflights.end();it++){
                        if(vecflights[i]->get_plane_id() == x){
                                found = true;
                                vecflights.erase(it);
                                break;
                        }
                        i++;
                }
        }
        else if(c == 2){
                cout <<"Please Enter the tail number of the flight\n";
                getline(cin,x); 

                vector<flight*>::iterator it;
                i =0;
                for(it = vecflights.begin(); it != vecflights.end();it++){
                        if(vecflights[i]->get_status() == "Cancelled"){
                                found = true;
                                vecflights.erase(it);
                        }
                        i++;
                }
        }
        else if(c == 3){
                cout <<"Please Enter the tail number of the flight\n";
                getline(cin,x); 

                vector<flight*>::iterator it;
                i =0;
                for(it = vecflights.begin(); it != vecflights.end();it++){
                        if(vecflights[i]->get_status() == "Completed"){
                                found = true;
                                vecflights.erase(it);
                        }
                        i++;
                }
        }
        else{
                cout <<"Unvalid choice\n"; exit (-1);
        }
        if (found == false){
                cout <<"The flight was not found\n";
        }
        
}
flight* flights::findFlight(){
        string id; unsigned int i;
        cout <<"Enter the tail number of the flight:\n";
        getline(cin,id);
        
        for(i=0 ; i < vecflights.size();i++){
                if (vecflights[i]->get_plane_id ()== id){
                        return vecflights[i];
                }
        }
        cout <<"The plane was not found\n";
        return NULL;
}
 // prints all enteries in the collection
 void flights::print_enteries(){
         cout <<"ALL FLIGHTS:\n";
         for(unsigned int i =0; i < vecflights.size(); i++){
                 cout<<endl;
                 cout <<"Tail number:"<< vecflights[i]->get_plane_id()<<"        Starting Time: "; vecflights[i]->prints();
                 cout <<"       Ending Time: "; vecflights[i]->printe(); cout<<endl <<"Number of passengers: "<<vecflights[i]->get_people()
                 << "   Number of pilots: "<<vecflights[i]->get_n_pilots() <<"    Number of co-pilot: "<<vecflights[i]->get_n_pilots()
                 <<"    Number of cabin: "<<vecflights[i]->get_n_crew()<< endl <<"Starting Letters of the Airport Code: "<<vecflights[i]->get_sairport_code()
                 <<"    Ending Letters of the Airport Code: "<< vecflights[i]->get_eairport_code()<< "Status: "<<vecflights[i]->get_status();
                cout <<endl;
         }
 }

 // prints details of one entity
void flights::print_oneEntity (){
        unsigned int i;

        vecflights[i] = findFlight();

                cout<<endl;
                 cout <<"Tail number:"<< vecflights[i]->get_plane_id()<<"        Starting Time: "; vecflights[i]->prints();
                 cout <<"       Ending Time: "; vecflights[i]->printe(); cout<<endl <<"Number of passengers: "<<vecflights[i]->get_people()
                 << "   Number of pilots: "<<vecflights[i]->get_n_pilots() <<"    Number of co-pilot: "<<vecflights[i]->get_n_pilots()
                 <<"    Number of cabin: "<<vecflights[i]->get_n_crew()<< endl <<"Starting Letters of the Airport Code: "<<vecflights[i]->get_sairport_code()
                 <<"    Ending Letters of the Airport Code: "<< vecflights[i]->get_eairport_code()
                 << "Status: "<<vecflights[i]->get_status(); 
                cout <<endl;
         

}

 // prints the flights with specific plane
void flights::printPlanFlights (){
        string id; // id of plane
        cout <<"Enter the ID number of the plane: \n";
        getline(cin,id);

        for(unsigned int i =0; i < vecflights.size(); i++){
                if(vecflights[i]->get_plane_id() == id){
                                        cout<<endl;
                 cout <<"Tail number:"<< vecflights[i]->get_plane_id() <<"        Starting Time: "; vecflights[i]->prints();
                 cout <<"       Ending Time: "; vecflights[i]->printe(); 
                cout <<endl;
                }
        }
}
/* 
 // prints all flights with specific crew
void flights::print_crew_flights(){
        string name;
        cout <<"Enter the name of crew:\n";
        getline(cin, name);
        for(unsigned int i =0 ; i < vecflights.size(); i++){
                if (name == vecflights[i]->get_cab() || name == vecflights[i]->get_cpilots() || name == vecflights[i]->get_pilots()){
                                         cout <<"flight's Tail number:"<< vecflights[i]->get_plane_id() <<"        Starting Time: "; vecflights[i]->prints();
                 cout <<"       Ending Time: "; vecflights[i]->printe();
                cout <<endl;
                }
        }
}
*/