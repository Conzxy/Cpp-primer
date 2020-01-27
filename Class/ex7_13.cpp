//
//ex7_13.cpp
//
//created by tsubaki-san on 20/1/26
//

#include"ex7_12.h"

int main()
{
	sales_data total(std::cin);
	if (!total.isbn().empty()) {
		std::istream& is = std::cin;
		while (is) {
			sales_data trans(is);
			if (!is)break;
			if (total.isbn() == trans.isbn())
				total.combine(trans);
			else {
				print(std::cout, total) << std::endl;
				total = trans;
			}
		}
		print(std::cout, total) << std::endl;
	}
	else {
		std::cerr << "No data?!" << std::endl;
		return -1;
	}

	return 0;
}