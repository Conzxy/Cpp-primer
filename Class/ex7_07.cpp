//
//ex7_07.cpp
//
//created by tsubaki-san on 20/1/27
//

#include"ex7_06.h"
using std::cin; using std::cout; using std::endl; using std::cerr;

int main() {
	sales_data total;
	if (read(cin,total))
	{
		sales_data trans;
		while (read(cin,trans))
		{
			if (total.isbn() == trans.isbn())
				total.combine(trans);
			else
			{
				print(cout, total)<<endl;
				total = trans;
			}
		}
		print(cout, total)<<endl;
	}
	else {
		cerr << "No data?!" << endl;
		return -1;
	}
	return 0;
}