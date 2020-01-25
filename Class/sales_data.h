//header guard
#ifndef SALES_DATA_H   //����δ����ʱΪ�棬���Ϊ����ִ�к�������ֱ������#endifָ����ֹ��Ϊ����ʡ��#ifndef��#endif֮��Ĳ���
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
	//��ʼ��������member data
	//���ۺ�ʱ��ֻҪ��Ķ��󱻴������ͻ�ִ�й��캯��
	sales_data() = default;//default constructor
	sales_data(const string& s) :bookNo(s) {}//������������������ԱĬ��ֵ���ڴ˿�Ҫ�ɲ�Ҫ��
	sales_data(const string& s, unsigned n, double p) :bookNo(s), units_sold(n), revenue(p) {}
	sales_data(istream& is) { read(is, *this); }//��is��ȡһ����Ϣ�����this�����У�this=sales_data *const)
	//member functions
	string isbn()const { return bookNo; }//�������ISBN���
	sales_data& combine(const sales_data&);//��һ��Sales_data����ӵ���һ��������
private:
	//A member declared in a private section of a class can only be accessed by member functions and friends of that class
	//privateһ�㶼��member data������Щmember data��ҪһЩ�򵥵�������ܵõ����ɴ˳�����private��member functions
	//��private�е�member funtions����Ϊ���������ݵã�ֻ����������������������������member data�ģ�һ��Ƚ�С
	double avg_price()const;	//�����۳��鼮��ƽ���۸�
	string bookNo;				//��ʾ���ISBN���
	unsigned units_sold = 0;	//��ʾ�������
	double revenue = 0.0;		//��ʾ�������������
};
//�ǳ�Ա�ӿں���(non-member interface functions)
sales_data add(const sales_data&, const sales_data&);//ִ������Sales_data����ļӷ�
ostream& print(ostream&, const sales_data&);		//��Sales_data�����ֵ�����ostream
istream& read(istream&, sales_data&);				//�����ݴ�istream���뵽Sales_data������


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
	cout << "������Ҫ��¼�����ISBN�롢������������:" << endl;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price * item.units_sold;
	return is;
}

ostream& print(ostream& os, const sales_data& item) {
	os << item.isbn() << " ������Ϊ:" << item.units_sold << " ������:"
		<< item.revenue << " ����Ϊ:" << item.avg_price();
	return os;
}

sales_data add(const sales_data& rhs, const sales_data& lhs) {
	sales_data sum = rhs;
	sum.combine(lhs);
	return sum;
}
#endif