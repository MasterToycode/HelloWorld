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

	// CDeriveA�Ĺ��캯��������CBase�Ĺ��캯������ʼ������ĳ�Ա����
	CDeriveA(int a1, int a2, int a3, int a4, int a5, int a6) : CBase(a1, a2, a3) 
	{
		ax = a4;
		ay = a5;
		az = a6;
	}

	void outshow()
	{
		CBase::showy();
		cout << "��������ʻ���ı�����Ա" << endl;
		CBase::showz();
		cout << "��������ʻ���Ĺ��г�Ա" << endl;
		showax();
		cout << "����������Լ���˽�г�Ա" << endl;
		showay();
		cout << "����������Լ��ı�����Ա" << endl;
	}

};


/*
˽�м̳У�
������Ի���Ĺ��кͱ�����Ա�������˽�г�Ա���ⲿ�޷����ʡ�
������Ի����˽�г�Ա��Ȼ��˽�г�Ա���ⲿ�޷����ʡ�
���������ͨ�����Ա�������ʻ���ĳ�Ա��

��˽�м̳��£���ʹ�������й��г�Ա������Ҳ�޷�ֱ�ӷ��ʻ���ĳ�Ա��
ֻ��������ĳ�Ա������������������ڲ����ʻ���ĳ�Ա��
����˽�м̳е�һ����Ҫ�ص㣬��ȷ���˶Ի���ķ�װ�����ء�
���ǣ�������������ĳ�Ա���������ⲿ���룬������ֱ�ӷ��ʻ����˽�г�Ա��
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
		cout << "��������ʻ���ı�����Ա" << endl;
		CBase::showz();
		cout << "��������ʻ���Ĺ��г�Ա" << endl;
		showbx();
		cout << "����������Լ���˽�г�Ա" << endl;
		showby();
		cout << "����������Լ��ı�����Ա" << endl;
	}
};


/*
�����̳У�
������Ի���Ĺ��г�Ա�����������ı�����Ա���ⲿ�޷�ֱ�ӷ��ʡ�
������Ի���ı�����Ա��Ȼ�Ǳ�����Ա���ⲿ�޷�ֱ�ӷ��ʡ�
���������ͨ�����Ա�������ʻ���ĳ�Ա��
��Ϊ����Ĺ��г�Ա�����������ı�����Ա�������������༰��������ֱ�ӷ�����Щ��Ա��
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
		cout <<endl<< "����������Լ���˽�г�Ա" << endl;
		CBase::showy(); 
		cout <<endl <<"��������ʻ���ı�����Ա" << endl;
		cout << "Base::x=" << CBase::y <<" "
			<< "���м̳У����������ڲ�����ֱ�ӷ��ʻ���ı�����Ա" << endl;// ���������ڲ�����ֱ�ӷ��ʻ���ı�����Ա
	}

	void showCyandBaseyfromOuterC() 
	{	
		showcy();
		cout <<endl<< "����������Լ��ı�����Ա" << endl;
		CBase::showz();
		cout <<endl<< "��������ʻ���Ĺ��г�Ա" << endl;
		cout << "Base::z=" << CBase::z << " "
			<< " ���м̳У����������ڲ�����ֱ�ӷ��ʻ���Ĺ��г�Ա" << endl;// ���������ڲ�����ֱ�ӷ��ʻ���Ĺ��г�Ա
	}
};

