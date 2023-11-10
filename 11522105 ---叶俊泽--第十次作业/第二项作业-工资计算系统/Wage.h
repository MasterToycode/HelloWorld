#include<iostream>
#include<string>
using namespace std;
class Employee 
{
protected:
	long int number;//工号
	string name;//姓名
	double salary;//工资

public:
	Employee(long int a,string b,double c=0):number(a),name(b),salary(c){}
};


class Salesman :public Employee 
{
protected:
	 double commrate;//提成
	double sales;//销售额
public:
	Salesman(long int a, string b,double e,double d=0.05,double c = 0):Employee(a,b,c),commrate(d),sales(e){}
	void pay() 
	{
		salary = sales * commrate;
	}

	void print() 
	{	
		cout << "员工：" << name << "本月的工资为：" << salary <<"元" << endl;
	}
};


class Salemanger :public Employee
{
protected:
	double commrate;//提成
	double monthsalary = 8000;
	double sales;
public:
	Salemanger(long int a, string b, double e, double d = 0.05, double c = 0) :Employee(a, b, c), commrate(d), sales(e) {}

	void pay1()
	{
		// 提成按照全部销售额计算
		double commission = sales * commrate;
		// 固定月薪 + 提成
		Salemanger::salary = monthsalary + commission;
		cout << salary << endl;
	}

	void print()
	{
		cout << "销售经理" << name << "本月的工资为：" << Salemanger::salary << "元" << endl;
	}

};