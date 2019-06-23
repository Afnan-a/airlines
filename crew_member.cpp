#include <iostream>
#include <string>
 using namespace std;

#include "crew_member.h"


        crew::crew()
	{
		name = " ";
		id = " ";
		type = " ";
	}
        crew::crew(string n,string i ,string t)
	{
		name = n; id=i; type = t;
	}
        void crew::setname(string n)
	{
		name = n;
	} 
        string crew::getname()const
	{
		return name;
	}
        void crew::setid(string i)
	{
		id = i;
	} 
        string crew::getid()const
	{
		return id;
	}
        void crew::settype(string t)
        {
		type =t;
	}
	string crew::gettype()const
	{
		return type;
	}
