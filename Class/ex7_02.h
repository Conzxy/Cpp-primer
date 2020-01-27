//
//ex7_02.h
//
//created by tsubaki-san on 20/1/26
//
#ifndef EX7_02_H
#define EX7_02_H

#include<string>

struct sales_data {
	sales_data& combine(const sales_data&);
	std::string isbn()const { return bookNo; };

	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};
sales_data& sales_data::combine(const sales_data& rhy) {
	units_sold += rhy.units_sold;
	revenue += rhy.revenue;
	return *this;
}

#endif
