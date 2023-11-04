#include<iostream>
using namespace std;
class CBase 
{
private:
	int x;
	void showx() { cout << "CBase::x=" << x << endl; }
protected:
	int y;
	void showy() { cout << "CBase::y=" << y << endl; }
public:
	int z;
	void showz() { cout << "CBase::z=" << z << endl; }
	
	CBase(int a1,int a2,int a3):x(a1) ,y(a2),z(a3) {}
};



class CDeriveA :private CBase 
{
private:
	int ax;
	void showax() { cout << "CDeriveA::ax=" << ax << endl; }
protected:
	int ay;
	void showay() { cout << "CDeriveA::ay=" << ay << endl; }
public:
	int az;
	void showaz() { cout << "CDeriveA::az=" << az << endl; }

	// CDeriveA的构造函数，调用CBase的构造函数来初始化基类的成员变量
	CDeriveA(int a1, int a2, int a3, int a4, int a5, int a6) : CBase(a1, a2, a3) 
	{
		ax = a4;
		ay = a5;
		az = a6;
	}

	void outshow()
	{
		CBase::showy();
		cout << "派生类访问基类的保护成员" << endl;
		CBase::showz();
		cout << "派生类访问基类的公有成员" << endl;
		showax();
		cout << "派生类访问自己的私有成员" << endl;
		showay();
		cout << "派生类访问自己的保护成员" << endl;
	}

};


/*
私有继承：
派生类对基类的公有和保护成员都变成了私有成员，外部无法访问。
派生类对基类的私有成员仍然是私有成员，外部无法访问。
派生类可以通过其成员函数访问基类的成员。

在私有继承下，即使派生类有公有成员，它们也无法直接访问基类的成员。
只有派生类的成员函数可以在派生类的内部访问基类的成员。
这是私有继承的一个重要特点，它确保了对基类的封装和隐藏。
但是，无论是派生类的成员函数还是外部代码，都不能直接访问基类的私有成员。
*/


class CDeriveB :protected CBase 
{
private:
	int bx;
	void showbx() { cout << "CDeriveB::bx=" << bx << endl; }
protected:
	int by;
	void showby() {  cout << "CDeriveB::by=" << by << endl; }
public:
	int bz;
	void showbz() { cout << "CDeriveB::bz=" << bz << endl; }

	CDeriveB(int a1, int a2, int a3, int a4, int a5, int a6) : CBase(a1, a2, a3), bx(a4), by(a5), bz(a6) {}
	
	void outshow() 
	{
		CBase::showy();
		cout << "派生类访问基类的保护成员" << endl;
		CBase::showz();
		cout << "派生类访问基类的公有成员" << endl;
		showbx();
		cout << "派生类访问自己的私有成员" << endl;
		showby();
		cout << "派生类访问自己的保护成员" << endl;
	}
};


/*
保护继承：
派生类对基类的公有成员变成了派生类的保护成员，外部无法直接访问。
派生类对基类的保护成员仍然是保护成员，外部无法直接访问。
派生类可以通过其成员函数访问基类的成员。
因为基类的公有成员变成了派生类的保护成员，仅允许派生类及其派生类直接访问这些成员。
*/


class CDeriveC :public CBase 
{
private:
	int cx;
	void showcx() {  cout << "CDeriveC::cx=" << cx << endl; }
protected:
	int cy;
	void showcy() { cout << "CDeriveC::cy=" << cy << endl; }
public:
	int cz;
	void showcz() { cout << "CDeriveC::cz=" << cz << endl; }

	CDeriveC(int a1, int a2, int a3, int a4, int a5, int a6) : CBase(a1, a2, a3), cx(a4), cy(a5), cz(a6) {}
	void showCxandBasexfromOuterC() 
	{
		showcx();
		cout <<endl<< "派生类访问自己的私有成员" << endl;
		CBase::showy(); 
		cout <<endl <<"派生类访问基类的保护成员" << endl;
		cout << "Base::x=" << CBase::y <<" "
			<< "公有继承，在派生类内部可以直接访问基类的保护成员" << endl;// 在派生类内部可以直接访问基类的保护成员
	}

	void showCyandBaseyfromOuterC() 
	{	
		showcy();
		cout <<endl<< "派生类访问自己的保护成员" << endl;
		CBase::showz();
		cout <<endl<< "派生类访问基类的公有成员" << endl;
		cout << "Base::z=" << CBase::z << " "
			<< " 公有继承，在派生类内部可以直接访问基类的公有成员" << endl;// 在派生类内部可以直接访问基类的公有成员
	}
};

