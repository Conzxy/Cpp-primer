//
//ex7_03.cpp
//
//created by tsubaki-san on 20/1/26
//

#include<iostream>
#include"ex7_02.h"
using std::cin; using std::cout; using std::endl; using std::cerr;

int main() {
	sales_data total;
	if (cin >> total.bookNo >> total.units_sold >> total.revenue)
	{
		sales_data trans;
		while (cin >> trans.bookNo >> trans.units_sold >> trans.revenue)
		{
			if (total.isbn() == trans.isbn())
				total.combine(trans);
			else
			{
				cout << total.bookNo << " " << total.units_sold << " " << total.revenue << endl;
				total = trans;
			}
		}
		cout << total.bookNo << " " << total.units_sold << " " << total.revenue << endl;
	}
	else {
		cerr << "No data?!" << endl;
		return - 1;
	}
	return 0;
}