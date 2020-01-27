//
//ex7_11.cpp
//
//created by tsubaki-san on 20/1/27
//

#include"ex7_11.h"

int main()
{
	sales_data item1;
	print(std::cout, item1)<<std::endl;

	sales_data item2("0-201-78345-X", 20, 3.0);
	print(std::cout, item2) << std::endl;

	sales_data item3("0-201-78345-X");
	print(std::cout, item3) << std::endl;

	sales_data item4(std::cin);
	print(std::cout, item4) << std::endl;

	return 0;
}