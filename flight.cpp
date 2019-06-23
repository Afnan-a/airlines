#include <cstring>
#include <cstdio>
#include <string>
#include <iostream>
#include <list>
#include <cctype>
#include <cstdlib>
using namespace std;
#include "flight.h"
#include "crew_member.h"
#include "plane.h"
#include "crew_members.h"
#include "planes.h"
#include <ctime>

extern crews *c;
extern planes *p;

	 flight::flight(){
                plane_id = NULL; 
		n_pilots=0;	
		n_crew = 0;	
		start_date = time(NULL);
		end_date = time(NULL);		
                sairport_code = new char(3);
                eairport_code = new char(3);
	/* 	*sairport_code = "  "; 
		*eairport_code ="   ";	 
                sairport_code = "   ";
                *eairport_code = NULL; */
		people =0;  
		status = " ";
                
	}

         flight::flight(char id[], int n1,int n2, time_t st, time_t e, char sc[], char ec[], int p, vector <string> pi ,vector <string> cpi, vector <string> cab, string stat){

                plane_id = id; 
		n_pilots=n2;	
		n_crew = n1;	
		start_date = st;
		end_date = e;		
                strcpy(sairport_code,sc);
                strcpy(eairport_code,ec);
		people =p;  
		status = stat;
                cabin_ids = cab;		//list of cabin crew IDs
	        pilot_ids = pi;
                copilot_ids = cpi;
         }

 void flight::set_pilots (){
        int n = get_n_pilots();    int co=0; //count   
        string id; 
        flight *temp;
        cout << n << endl;
       while (co < n){
                cout <<"Please Enter pilot's #"<<co+1<<" ID:\n";
             //   cin.ignore();
                getline(cin,id); 
                    
                pilot_ids.push_back(id);
        //        pilot_ids.push_back(c->search_crew(id));
               
                co++;

               // temp = crewsobj.search_crew(id);
        
                 /*    if(c->search_crew(id)->gettype() == "Pilot"){
                         
                                pilot_ids.push_back(crewsobj->search_crew(id));
                                co++;
                        }
                        else{
                                cout <<"The ID you Entered was not for a pilot\n";
                        } */
                
        }

 }
vector<string> flight::get_pilots(){
        return pilot_ids;
}

void flight::set_cpilots (){
        int n = get_n_pilots();    int c=0; //count   
        string id; 
        flight *temp;

       while (c < n){
                cout <<"Please Enter Co-pilot's #"<<c+1<<" ID:\n";
                getline(cin,id); 
           copilot_ids.push_back(id);
           c++;
         //       copilot_ids.push_back(crewsobj->search_crew(id));
/* 
               // temp = crewsobj.search_crew(id);
        
                       if(crewsobj->search_crew(id)->gettype() == "Co-pilot"){
                         
                                copilot_ids.push_back(crewsobj->search_crew(id));
                                c++;
                        }
                        else{
                                cout <<"The ID you Entered was not for a co-pilot\n";
                        } */
                
        }
}
vector <string> flight::get_cpilots(){
        return copilot_ids;
}

void flight::set_cab (){
        int n = get_n_crew();    int c=0; //count   
        string id; 
        flight *temp;

       while (c < n){
                cout <<"Please Enter Cabin's #"<<c+1<<" ID:\n";
                getline(cin,id); 

                cabin_ids.push_back(id);
                c++;
               // temp = crewsobj.search_crew(id);
        
                 /*       if(crewsobj->search_crew(id)->gettype() == "Cabin"){
                         
                                cabin_ids.push_back(crewsobj->search_crew(id));
                                c++;
                        }
                        else{
                                cout <<"The ID you Entered was not for a cabin\n";
                        } */
                
        }
}
vector <string> flight::get_cab(){
        return cabin_ids;
}

void flight::set_startdate(){
                struct tm stime;
  
                int year;
                int month ;
                int day ;
                int hour;
                int min ;
               // int sec =0; 

               cout <<endl<<"Enter The starting date month/day/year :\n";
               scanf("%d/%d/%d",&month,&day,&year);
                
               cout <<endl<<"Enter The starting time Hours:Minutes :\n";
               scanf("%d:%d",&hour,&min);

                stime.tm_year = year-1900; 
                stime.tm_mon = month-1;
                stime.tm_mday = day;
                stime.tm_hour = hour;
                stime.tm_min = min;
               // stime.tm_sec = 0;

                 start_date = mktime(&stime);
                const struct tm *when = gmtime(&start_date); 
}
        time_t flight::get_startdate(){
                return start_date;
        //         const struct tm *when = gmtime(&start_date); 
         //          printf("That is: %s\n", asctime(when));
        }

        void flight::set_enddate(){
                struct tm stime;
  
                int year;
                int month ;
                int day ;
                int hour;
                int min ;
                int sec = 0; 

               cout <<endl<<"Enter The ending date month/day/year :\n";
               scanf("%d/%d/%d",&month,&day,&year);
                
               cout <<endl<<"Enter The ending time Hours:Minutes :\n";
               scanf("%d:%d",&hour,&min);

                stime.tm_year = year-1900; 
                stime.tm_mon = month-1;
                stime.tm_mday = day;
                stime.tm_hour = hour;
                stime.tm_min = min;
                stime.tm_sec = sec;

                 end_date = mktime(&stime);
                 const struct tm *when = gmtime(&end_date);
        }
        time_t flight::get_enddate(){
                return end_date;
              //    const struct tm *when = ,gmtime(&end_date); 
              //     printf("That is: %s\n", asctime(when));
        }

        void flight::set_plane_id (){
                char tailnum[20] ;
                planes planesobj;

                cout << "Enter the tail number of the plane to be used for this flight: \n";
                cin.getline(tailnum,20); 
               
             //  plane_id = planesobj.search_plane(tailnum)->getTail_number();

             plane_id = tailnum;
           
        }

        char* flight::get_plane_id () const{
                return plane_id;
        }

        void flight::set_n_pilots(){

          /*       if ((end_date - start_date) > 8){
                       n_coPilot =2;
                        n_pilots = 2;}
               else{
                     n_coPilot = 1;
                     n_pilots = 1;
               } */
               n_coPilot = 2;
               n_pilots =2;
        }

        int flight::get_n_pilots()const{
                return n_pilots; 
        }

        void flight::set_n_crew(){
               int  numcrew =3;
                n_crew =numcrew;

         
              /*   if ((end_date - start_date) > 8){
                numcrew = 2 * (p->search_plane(plane_id)->getMin_crew());
               n_crew =numcrew;}
               else{
                       numcrew = p->search_plane(plane_id)->getMin_crew();
                        n_crew =numcrew;
               } */
        }
        int flight::get_n_crew()const{
                return n_crew;
        }

        void flight::set_sairport_code(){
                
                char code[4];
                
                cout <<"Enter the first 3 LETTERS of the airport code: \n";

                cin.getline(code,4); 
                sairport_code = code;
         //       cin.clear();
           
        }
        char* flight::get_sairport_code()const{
                return sairport_code;
        }

        void flight::set_eairport_code(){
               char codee[4];
                
                cout <<"Enter the last 3 LETTERS of the airport code: \n";
               
                cin.getline(codee,4); //cin.ignore();
                eairport_code= codee;
        }
        char* flight::get_eairport_code()const{
                return eairport_code;
        }

        void flight::set_people(){
                
               bool enough = true;
               int numpeople;
         
                        cout << "Enter number of passengers: \n";
                        
                        cin >> numpeople; cin.ignore();

                  /*     if (numpeople > (p->search_plane(plane_id)->getSeats())){
                                
                                cout << "The number of passengers exceeds the number of seats\n"
                                <<"Please RE-";
                        }
                        else{
                                people = numpeople;
                                
                        }*/
                        
                                people = numpeople;
        }

        int flight::get_people()const{
                return people;
        }

        void flight::set_status (){
                cout <<"If the flight is COMPLETED enter key(1). To CANCELE the flight enter (2)\n";
                int k; cin>>k; cin.ignore();
             while(k != 1 || k != 2){
                if (k == 1){
                        status = "Completed";
                }
                else if (k == 2){
                        status = "Cancelled";
                }
                else{
                        cout <<"Please Enter a Valid key (1 to set it as completed, 2 to set it as Cancelled)\n";
                        cin >> k;      
                }
             }
        }

        string flight::get_status()const{
                return status;
        }

void flight::prints(){
        const struct tm *when = gmtime(&start_date); 
          printf("That is: %s\n", asctime(when));
}

void flight::printe(){
        const struct tm *when = gmtime(&end_date); 
             printf("That is: %s\n", asctime(when));
}

void flight::printpi(){

         vector<string>::iterator it;
                
                for( it = pilot_ids.begin(); it != pilot_ids.end();it++){
                        cout <<" "<<*it;
                }
                cout <<endl;
}



void flight::printcpi(){

         vector<string>::iterator it;
                
                for( it = copilot_ids.begin(); it != copilot_ids.end();it++){
                        cout <<" "<<*it;
                }
                 cout <<endl;
}

 void flight::printcab(){
                  vector<string>::iterator it;
                
                for( it = cabin_ids.begin(); it != cabin_ids.end();it++){
                        cout <<" "<<*it;
                }
                cout <<endl;

 }