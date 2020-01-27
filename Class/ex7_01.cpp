//
//ex7_01.cpp
//
//created by tsubaki-san on 20/1/26
//

#include<iostream>
#include<string>
using namespace std;
struct sales_data {
	string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};
int main() {
	sales_data total;
	if (cin >> total.bookNo >> total.units_sold >> total.revenue)
	{
		sales_data trans;
		while (cin >> trans.bookNo >> trans.units_sold >> trans.revenue) {
			if (total.bookNo == trans.bookNo)
			{
				total.units_sold += trans.units_sold;
				total.revenue += trans.revenue;
			}
			else {
				cout << total.bookNo <<" "<<total.units_sold <<" "<< total.revenue << endl;
				total = trans;
			}
		}
		cout << total.bookNo <<" "<<total.units_sold <<" "<<total.revenue << endl;
	}
	
	else {
		cerr << "No data?!" << endl;
		return -1;
	}
	return 0;
}