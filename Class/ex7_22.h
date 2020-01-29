//
//ex7_22.h
//
//created by tsubaki-san on 20/1/28
//

#ifndef EX7_22_H
#define EX7_22_H

#include<string>
#include<iostream>

class Person;

class Person {
	friend std::istream& read(std::istream&, Person&);
	friend std::ostream& print(std::ostream&, const Person&);
public:
	Person() = default;
	Person(const std::string n, const std::string s) :name(n), address(s) {}
	Person(std::istream& is) { read(is, *this); }

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
//interface functions
std::istream& read(std::istream&, Person&);
std::ostream& print(std::ostream&, const Person&);

std::istream& read(std::istream& is, Person &item) {
	is >> item.name >> item.address;
	return is;
}

std::ostream& print(std::ostream& os, const Person &item) {
	os << item.name << " " << item.address;
	return os;
}

#endif
/*class Solution {
public:
	int maxArea(vector<int>& height) {
		if (height.empty()) return 0;
		vector<int>::iterator b, e;
		b = height.begin();
		e = height.end() - 1;
		int result = 0;
		while (b < e) {
			if (*b > * e) {
				result = result < (int)(e - b) * (*e) ? (int)(e - b) * (*e) : result;
				e--;
			}
			else {
				result = result < (int)(e - b) * (*b) ? (int)(e - b) * (*b) : result;
				b++;
			}
		}
		return result;
	}
};*/