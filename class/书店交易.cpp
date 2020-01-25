//使用2.6.1节练习定义的sales_data类为1.6节的交易程序编写一个新版本
#include<iostream>
#include"sales_data.h"
using namespace std;
int main(int argc,char **argv)
{
	sales_data total;//保存下一条交易记录的变量
	//读入第一条交易记录，并确保有数据可以处理
	if (read(cin, total)){
		sales_data trans;//保存和的变量
		//读入并处理剩余交易记录
			while (read(cin, trans)) {
				//如果仍在处理相同的书
				if (total.isbn() == trans.isbn())//error:total.bookNo==trans.bookNo 不准访问private
					total.combine(trans);//更新总销售额，总收入
				else {
					//打印前一本书的结果
					cout << "前一本书的ISBN码:";
					print(cout, total) << endl;
					total = trans;//total现在表示下一本书的销售额
					system("pause");
						//默认赋值：
						//total.bookNo=trans.bookNo;
						//total.units_sold=trans.units.sold;
						//total.revenue=trans.revenue;
				}
			}
			cout << "最后一本书的ISBN码:";
		print(cout, total) << endl;//打印最后一本书的结果
	}
	else {
		cerr << "NO data?!" << endl;//输出错误信息
	}
	return 0;
}