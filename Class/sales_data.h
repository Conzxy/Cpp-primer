//header guard
#ifndef SALES_DATA_H   //变量未定义时为真，检查为真则执行后续操作直到遇到#endif指令终止，为假则省略#ifndef到#endif之间的部分
#define SALES_DATA_H

#include<iostream>
#include<string>
using namespace std;
class sales_data {
	//friends of this class
	friend sales_data add(const sales_data&, const sales_data&);
	friend ostream& print(ostream&, const sales_data&);
	friend istream& read(istream&, sales_data&);
	//friends of this class can access the private section of this class
public:
	//Member:either member data or member functions
	//A member declared in a public section of a class can be accessed by anyone

	//constructor
	//初始化类对象的member data
	//无论何时，只要类的对象被创建，就会执行构造函数
	sales_data() = default;//default constructor
	sales_data(const string& s) :bookNo(s) {}//编译器将赋予其他成员默认值（在此可要可不要）
	sales_data(const string& s, unsigned n, double p) :bookNo(s), units_sold(n), revenue(p) {}
	sales_data(istream& is) { read(is, *this); }//从is读取一条信息后存入this对象中（this=sales_data *const)
	//member functions
	string isbn()const { return bookNo; }//返回书的ISBN编号
	sales_data& combine(const sales_data&);//将一个Sales_data对象加到另一个对象上
private:
	//A member declared in a private section of a class can only be accessed by member functions and friends of that class
	//private一般都是member data，但有些member data需要一些简单的运算才能得到，由此出现了private的member functions
	//即private中得member funtions就是为了隐藏数据得，只不过这个函数是用来计算这个类中member data的，一般比较小
	double avg_price()const;	//返回售出书籍的平均价格
	string bookNo;				//表示书的ISBN编号
	unsigned units_sold = 0;	//表示书的销量
	double revenue = 0.0;		//表示书的总销售收入
};
//非成员接口函数(non-member interface functions)
sales_data add(const sales_data&, const sales_data&);//执行两个Sales_data对象的加法
ostream& print(ostream&, const sales_data&);		//将Sales_data对象的值输出到ostream
istream& read(istream&, sales_data&);				//将数据从istream读入到Sales_data对象中


double sales_data::avg_price()const {
	if (units_sold)
		return revenue / units_sold;
	else
		return 0;
}

sales_data& sales_data::combine(const sales_data& rhs) {
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}

istream& read(istream& is, sales_data& item) {
	double price = 0;
	cout << "请输入要记录的书的ISBN码、销售量、单价:" << endl;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price * item.units_sold;
	return is;
}

ostream& print(ostream& os, const sales_data& item) {
	os << item.isbn() << " 销售量为:" << item.units_sold << " 总收入:"
		<< item.revenue << " 均价为:" << item.avg_price();
	return os;
}

sales_data add(const sales_data& rhs, const sales_data& lhs) {
	sales_data sum = rhs;
	sum.combine(lhs);
	return sum;
}
#endif