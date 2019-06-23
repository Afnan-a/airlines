#include <list>
#include <vector>
#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <fstream>
#include <iterator>
#include "crew_member.h"
#include "crew_members.h"
using namespace std;


//crew crewobj;
// vector<crew*> crewvec;

void crews::storecrew()
{
    ofstream fout;
    fout.open("crews.dat");
    fout << crewvec.size() << endl;
    
    vector<crew*>::iterator it;
    crew *temp;
    for ( it = crewvec.begin(); it != crewvec.end(); ++it)
    {
        temp = *it;
        fout << temp->getid() << " " << temp->getname() << " " << temp->gettype() <<endl;
    }
    fout.close();
}

void crews::loadcrew()
{
    ifstream fcin;
     string type1, name1,id;
  
    fcin.open("crews.dat");
    fcin >> ccount; fcin.ignore();
    
    for (int i = 0; i <  ccount ; i++)
    {
        fcin >> name1 >> id >> type1 ;
         crewvec.push_back( new crew(name1,id,type1));
    }

    fcin.close();
    
}

 

void crews::add_crew(){
        vector<crew>::iterator it;
        
        string type1, name1,id;
        int  choice;
        crew* temp;

        cout <<"Enter The name of the Crew member:\n";
        getline(cin,name1);
        
        cout <<"Enter the ID:\n";
        cin >>id; cin.ignore();
        
        cout <<"Choose the type:\n"<<"1- Cabin\n"
        <<"2- Pilot\n"
        <<"3- Co-pilot\n";
        cin>>choice; cin.ignore();
        
        if (choice==1){
                type1 = "Cabin";

               temp = new crew(name1,id,type1);
                    crewvec.push_back(temp);
        }
        else if (choice == 2){
                type1 = "Pilot;";
                temp = new crew(name1,id,type1);
                crewvec.push_back(temp);
        }
        else if (choice == 3){
                type1 = "Co-pilot;";
                temp = new crew(name1,id,type1);
                crewvec.push_back(temp);
        }
        else{
                cout <<"Invalid selection\n";
                exit (1);
        }
}
void crews::delete_crew(){
        string idnum; unsigned int i;
        bool found = false;
        vector<crew*>::iterator it;

        cout <<"Enter the Id number of the crew to delete\n";
        getline(cin ,idnum);
  
        for(i =0, it = crewvec.begin() ; it != crewvec.end() && i < crewvec.size();i++, it++){
                if(crewvec[i]->getid() == idnum){
                   found = true;
                   crewvec.erase(it);   
                   break;  
                }
        }
        if (found == false){ cout <<"The crew member was not found\n";}
}
crew* crews::search_crew(string idnum){
         string s1; unsigned int i;       bool found = false;

                for (i =0; i < crewvec.size() ;i++ ){
                        if(crewvec[i]->getid() == idnum){
                               found = true;
                                return  crewvec[i];
                        }
                }
        if (found == false){ cout <<"No results were found\n";}
        return NULL;
}

vector<crew*> crews::get_crewlist(){
        return crewvec ;
}

void crews::print_all_crew(){
        unsigned int i;
        vector<crew*>::iterator it;

        for(i =0, it = crewvec.begin() ; it != crewvec.end() && i < crewvec.size();i++, it++){
              cout <<"Crew Member #"<<i+1
              <<"       Name: "<<crewvec[i]->getname()<<"       ID: "<<crewvec[i]->getid()<<
              "        Type: "<<crewvec[i]->gettype()<<endl;
        }
}

void crews::print_entity_crew(){
        string idnum;
        unsigned int i;

        cout <<"Enter the ID number of the crew to print: \n";
        getline(cin,idnum);

        crewvec[i]= search_crew(idnum);
        
        if (crewvec[i] == NULL){
                cout << "The crew member was not found\n";
        }
        else{
                cout << "The crew member name's: "<< crewvec[i]->getname()
                <<"     Type: "<< crewvec[i]->gettype()
                <<"     Id: "<< crewvec[i]->getid() << endl;
        }
}

void crews::edit_crew(){
        string idnum, type;
        int choice; unsigned int i;

        cout << "Enter the ID number of the crew member to edit: \n";
        getline(cin,idnum);

        crewvec[i] = search_crew(idnum);

        if (crewvec[i] != NULL){
                cout <<"Choose what type do you want to assign to this crew member:\n"
                <<"1- Pilot\n"<<"2- Co-pilot\n"<< "3- Cabin\n";
                cin >> choice; cin.ignore();

                switch(choice){
                        case 1: crewvec[i]->settype("Pilot"); break;
                        case 2: crewvec[i]->settype("Co-pilot"); break;
                        case 3: crewvec[i]->settype("Cabin"); break;
                        default: {
                                cout << "Invalid Entry\n";
                                exit (1);
                        }
                }
        }
}