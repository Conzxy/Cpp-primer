//
//ex7_12.h
//
//created by tsubaki-san on 20/1/26
//

#ifndef EX7_12_H
#define EX7_12_H

#include<iostream>
#include<string>

class sales_data;
std::istream& read(std::istream&, sales_data&);

class sales_data {
public:
	sales_data() = default;
	sales_data(const std::string& s) :bookNo(s) {}
	sales_data(const std::string& s, unsigned n, double p) :
		bookNo(s), units_sold(n), revenue(p* n) {}
	sales_data(std::istream& is) { read(is, *this); }

	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;

	std::string isbn()const { return bookNo; };
	sales_data& combine(const sales_data&);
};
sales_data add(const sales_data&, const sales_data&);

std::ostream& print(std::ostream&, const sales_data&);

//member functions
sales_data& sales_data::combine(const sales_data& rhs) {
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}

//nonmember functions
sales_data add(const sales_data& rhs, const sales_data& lhs) {
	sales_data sum = rhs;
	sum.combine(lhs);
	return sum;
}

std::istream& read(std::istream& is, sales_data& item) {
	double price = 0.0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price * item.units_sold;
	return is;
}

std::ostream& print(std::ostream& os, const sales_data& item) {
	os << item.bookNo << item.units_sold << item.revenue;
	return os;
}

#endif