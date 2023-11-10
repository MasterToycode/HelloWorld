#include"Wage.h"
int main() 
{
	cout << "请依次输入该销售员工的工号，姓名和本月销售额";
	long int number1;
	string name1;
	double sales;
	cin >> number1 >> name1 >> sales;
	Salesman saleman1(number1, name1, sales);
	saleman1.pay();
	saleman1.print();


	cout << "请依次输入该销售员工的工号，姓名和本月销售额";
	long int number2;
	string name2;
	double sales2;
	cin >> number2 >> name2 >> sales2;
	Salesman saleman2(number2, name2, sales2);
	saleman2.pay();
	saleman2.print();



	cout << "请依次输入该销售经理的工号，姓名和本月销售额";
	long int number3;
	string name3;
	double sales3;
	cin >> number3 >> name3>>sales3;
	// 销售总额应该是所有销售员的销售额之和
	double totalSales = sales + sales2 + sales3;
	Salemanger salemanger1(number3, name3, totalSales);
	salemanger1.pay1();
	salemanger1.print();

}