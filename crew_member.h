#ifndef CREW_MEMBER_H
#define CREW_MEMBER_H

#include <string>
using namespace std;

class crew {
private:
	string name;
	string id;
	string type; // type of the crew (pilot or cabin)
public:
	crew();
	crew(string,string ,string );
	void setname(string);
	string getname()const;
	void setid(string);
	string getid()const;
	void settype(string);
	string gettype()const;
};
#endif
