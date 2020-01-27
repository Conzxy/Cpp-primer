//
//ex7_05.h
//
//created by tsubaki-san on 20/1/26
//

#ifndef EX7_05_H
#define EX7_05_H

#include<string>

class Person {
public:
	std::string getname()const { return name; };
	std::string getaddress()const { return address; };
	//
	//use trialing return type
	//auto getname()const->std::string const&{return name;};
	//auto getaddress()const->std::string const&{return address;};
	//
private:
	std::string name;
	std::string address;
};

#endif