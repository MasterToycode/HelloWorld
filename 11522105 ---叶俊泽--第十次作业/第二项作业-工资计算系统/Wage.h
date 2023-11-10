#include<iostream>
#include<string>
using namespace std;
class Employee 
{
protected:
	long int number;//����
	string name;//����
	double salary;//����

public:
	Employee(long int a,string b,double c=0):number(a),name(b),salary(c){}
};


class Salesman :public Employee 
{
protected:
	 double commrate;//���
	double sales;//���۶�
public:
	Salesman(long int a, string b,double e,double d=0.05,double c = 0):Employee(a,b,c),commrate(d),sales(e){}
	void pay() 
	{
		salary = sales * commrate;
	}

	void print() 
	{	
		cout << "Ա����" << name << "���µĹ���Ϊ��" << salary <<"Ԫ" << endl;
	}
};


class Salemanger :public Employee
{
protected:
	double commrate;//���
	double monthsalary = 8000;
	double sales;
public:
	Salemanger(long int a, string b, double e, double d = 0.05, double c = 0) :Employee(a, b, c), commrate(d), sales(e) {}

	void pay1()
	{
		// ��ɰ���ȫ�����۶����
		double commission = sales * commrate;
		// �̶���н + ���
		Salemanger::salary = monthsalary + commission;
		cout << salary << endl;
	}

	void print()
	{
		cout << "���۾���" << name << "���µĹ���Ϊ��" << Salemanger::salary << "Ԫ" << endl;
	}

};