#include<iostream>
using namespace std;
class A
{
public:
	A() { f(); }
	void virtual f()
	{
		cout << "A::f" << endl;
	}

	void g()
	{
		cout << "A::g" << endl;
	}

	void h()
	{
		f(); g();

	}
};




class B :public A
{
public:
	B() { f(); }
	void virtual f()
	{
		cout << "B::f" << endl;
	}

	void g() {
		cout << "B::g" << endl;
	}
};



int main()
{
	A a;//��ȻA�Ĺ��캯���д���f����������C++�еĹ��캯�������ڶ�̬�ԣ�
	cout << endl;
	B b;//�����ڹ���B��ʱ����Ӧ�Ĺ��캯��ֻ������Լ���Ӧ��f������

	cout << endl;
	A* p = &b;
	a.f();//ֱ�ӵ���A�Լ���f����
	b.f();//ֱ�ӵ���B�Լ���f����
	b.g();//ֱ�ӵ���B�Լ���g����
	a.g();//ֱ�ӵ���a�Լ���g����

	cout << endl;
	b.h();//��ΪBû�ж���h����
	//����A��h����������ĺͺ����ټ�ӵ���B�޸Ĺ����麯��f������A��g��������Ϊg�����麯��
	a.h();//ֱ�ӵ���A��h�������ټ�ӵ���A�Լ���f��g����

	cout << endl;
	p->f();//��Ȼָ��p��������A�࣬����f���麯����p���Ե���B�е��޸Ĺ���f����
	p->g();//pָ����B�࣬����p��������A������g�����麯��������ֻ�ܵ���B�е�A���g����
	p->h();//���ͬb.h()��һ����Ч��
	//���캯����ȷ���ģ������ڶ�̬�ԣ�����
}