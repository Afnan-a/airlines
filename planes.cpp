#include <iostream>
#include <cstring>
#include <string>
#include <list>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <iterator>

using namespace std;
#include "planes.h"
#include "plane.h"


void planes::storeplane()
{
    ofstream fout;
    fout.open("planes.dat");
    fout << vecplane.size() << endl;
    
    plane *temp;
    vector<plane*>::iterator it;

    for (it = vecplane.begin(); it != vecplane.end(); ++it)
    {
        temp = *it;
        fout << temp->getTail_number() << " " << temp->getModel() << " " << temp->getPlane_make() 
         << " " << temp->getRange()  << " " << temp->getSeats()  << " " << temp->getMin_crew() 
         <<endl;
    }
    fout.close();
}

void planes::loadplane()
{
    ifstream fcin;
    string str1, tailnum;
    int model_x, numseat, rang, mcrew;
  
    fcin.open("planes.dat");
    fcin >> pcount; fcin.ignore();
    
    for (int i = 0; i <  pcount ; i++)
    {
        fcin >> tailnum >> model_x >> str1 >> rang >> numseat >> mcrew;
         vecplane.push_back(new plane(str1,model_x,tailnum,numseat,rang,mcrew));
    }

    fcin.close();
    
}

void planes::add_plane(){
        string str1, tailnum;
        int model_x, numseat, rang, mcrew;


        cout << endl <<"Adding a Plane\n";
        cout << "Enter The Make of the plane: \n";
        cin.ignore();
        getline(cin, str1);
        cout <<"Enter the model number:\n";
        cin >> model_x; cin.ignore();
        cout <<"Enter The tail number:\n";
        getline(cin,tailnum); 
        cout <<"Enter number of seats: \n";
        cin >>numseat;  cin.ignore();
        cout << "Enter the range :\n";
        cin >>rang; cin.ignore();
        cout <<"Enter the minimum number of crew: \n";
        cin >>mcrew; cin.ignore();

     //   extern planes p = new plane(str1,model_x,tailnum,numseat,rang,mcrew);;

        plane *temp = new plane(str1,model_x,tailnum,numseat,rang,mcrew);

        vecplane.push_back(temp); 
}
void planes::delete_plane (){
        string x;
        unsigned int i;
        bool found = false;
        cout <<"Deleting Plane\n";
        cout <<"Please Enter the tail number of the plane\n";
        getline(cin,x); 

        vector<plane*>::iterator it;
        i =0;
        if(vecplane.empty()){
                cout <<"NO PLANES\n";
        }
        for(it = vecplane.begin(); it != vecplane.end();it++){
                if(vecplane[i]->getTail_number() == x){
                        found = true;
                        vecplane.erase(it);
                        break;
                }
                i++;
        }
        if (found == false){
                cout <<"The Plane was not found.\n";
        }
}
void planes::edit_plane (){
        cout <<"Edit Plane\n";
        int  choice,newnum;
        string tailnum;
        unsigned int i;
        bool found = false;

        do{
                cout <<"Please Enter the tail number of the plane\n";
                getline(cin,tailnum);       
                cout <<"select one of the options below to edit:\n"
                        <<" 1- Range \n"
                        <<" 2- Number of seats\n"
                        <<" 3- Minimum number of crew members\n";
                        cin >>choice; cin.ignore();

                for(i = 0; i < vecplane.size();i++){
                        if(vecplane[i]->getTail_number() == tailnum){
                                found = true;

                                if(choice ==1){
                                        cout <<"Enter the new Range:\n";
                                         cin >>newnum ; cin.ignore();

                                        vecplane[i]->setRange(newnum);
                                }
                                else if (choice==2){
                                        cout <<"Enter the new number of seats:\n";
                                         cin >>newnum ; cin.ignore();

                                        vecplane[i]->setSeats(newnum);
                                }
                                else if (choice==3){
                                        cout <<"Enter the new minimum of the crew members :\n";
                                         cin >>newnum ; cin.ignore();

                                        vecplane[i]->setMin_crew(newnum);
                                }
                                else{
                                        cout <<"The selected option was invalid\n"<<"select a valid option please\n";
                                }
                                break;
                        }
                }
        }while (choice !=1 || choice !=2|| choice !=3 || choice !=4);
        if (found == false){
                cout <<"The Plane was not found.\n";
        }
}
plane* planes::search_plane(char* tailnum){

        unsigned int i =0;
      
        vector<plane*>::iterator it;
   
                for(it = vecplane.begin(); it != vecplane.end();it++){
                        if(vecplane[i]->getTail_number() == tailnum){
                                
                                return vecplane[i];
                        }
                        i++;
                } 
                cout <<"The plane was not found\n";
       return NULL;
}

void planes::print_all_planes(){
         vector <plane*>::iterator it;
        unsigned int i;
         for(i=0; i< vecplane.size() ;i++){
                 cout <<"Plane #"<<i+1<<"\n       SEATS: "<< vecplane[i]->getSeats()
                 <<"    MODEL: "<< vecplane[i]->getModel() 
                 <<"      MAKE: "<<vecplane[i]->getPlane_make()
                 <<"    TAIL NUMBER: "<<vecplane[i]->getTail_number()
                 <<"    RANGE: "<<vecplane[i]->getRange()
                 <<"    Crew MEMBER: "<< vecplane[i]->getMin_crew() <<endl;
         }
}

void planes::print_entity(){
         char tailnum[20];
       
        vector<plane*>::iterator it;            bool found =false;   unsigned int i;
     
        cout << "Enter the tail number of the plane: \n";
        cin.getline(tailnum,20);


        vecplane[i] = search_plane(tailnum);

        if (search_plane(tailnum) == NULL){
                cout <<"The plane was not found\n";
        }
        else{
                cout <<"Plane's Make: "<<  vecplane[i]->getPlane_make()
                <<"     Model: "<<  vecplane[i]->getModel()
                <<"     Range: " <<  vecplane[i]->getRange()
                <<"     Seats: " <<  vecplane[i]->getSeats()
                <<"     Minimum number of crew members: " <<  vecplane[i]->getMin_crew()
                <<"     Tail number: "<<  vecplane[i]->getTail_number() << endl;
        }
}
