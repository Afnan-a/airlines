#ifndef PLANE_H
#define PLANE_H

#include <string>

class plane{

private :
	string plane_make;
	int model;
	string tail_number;
	int seats; // the capacity for seats
	int range;
	int min_crew;
public:
	plane();
	plane(string, int, string, int,int,int);
	void setPlane_make(string);
	string getPlane_make()const;
	void setModel(int);
	int getModel()const;
	void setTail_number(string);
	string getTail_number();
	void setSeats(int);
	int getSeats()const;
	void setRange(int);
	int getRange()const;
	void setMin_crew(int);
	int getMin_crew()const;
};

#endif
