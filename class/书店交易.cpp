//ʹ��2.6.1����ϰ�����sales_data��Ϊ1.6�ڵĽ��׳����дһ���°汾
#include<iostream>
#include"sales_data.h"
using namespace std;
int main(int argc,char **argv)
{
	sales_data total;//������һ�����׼�¼�ı���
	//�����һ�����׼�¼����ȷ�������ݿ��Դ���
	if (read(cin, total)){
		sales_data trans;//����͵ı���
		//���벢����ʣ�ཻ�׼�¼
			while (read(cin, trans)) {
				//������ڴ�����ͬ����
				if (total.isbn() == trans.isbn())//error:total.bookNo==trans.bookNo ��׼����private
					total.combine(trans);//���������۶������
				else {
					//��ӡǰһ����Ľ��
					cout << "ǰһ�����ISBN��:";
					print(cout, total) << endl;
					total = trans;//total���ڱ�ʾ��һ��������۶�
					system("pause");
						//Ĭ�ϸ�ֵ��
						//total.bookNo=trans.bookNo;
						//total.units_sold=trans.units.sold;
						//total.revenue=trans.revenue;
				}
			}
			cout << "���һ�����ISBN��:";
		print(cout, total) << endl;//��ӡ���һ����Ľ��
	}
	else {
		cerr << "NO data?!" << endl;//���������Ϣ
	}
	return 0;
}