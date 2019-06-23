#include <iostream>
#include <string>
 using namespace std;

#include "plane.h"

 plane::plane()
{
	plane_make =" ";
	model =0;
	tail_number = " ";
	seats = 0;
	range = 0;
	min_crew = 0;// minimum crew memebers
}

 plane::plane(string make, int m, string t, int s,int r,int mc)
 {
	plane_make = make;
	model = m;
	tail_number = t;
	seats =s;
	range = r;
	min_crew = mc;
 }
 void  plane::setPlane_make(string make)
 {
	plane_make = make;
 }
 string  plane::getPlane_make()const
 {
	return plane_make;
 }
 void  plane::setModel(int m)
 {
	model = m;
 }
 int   plane::getModel()const
 {
	return model;
 }
 void  plane::setTail_number(string t)
 {
 	tail_number = t;
 }
 string   plane::getTail_number()
 {
	return tail_number;
 }
 void  plane::setSeats(int s)
 { 
    seats =s;
 }
 int   plane::getSeats()const
 {
	return seats;
 }
 void  plane::setRange(int r)
 {
	range = r;
 }
 int   plane::getRange()const
 {
	return range;
 }
 void  plane::setMin_crew(int m)
 {
   	min_crew = m;
 }
 int   plane::getMin_crew()const
 {
	return min_crew;
 }


