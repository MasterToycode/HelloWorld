#include <iostream>
#include <string>
using namespace std;
class A
{
public:
	int i;	char c;  string s;

	A() : i(0), c('\0'), s("") { cout << "wucan����A" << endl; }
	A(int x1, char x2, string x3) :i(x1), c(x2), s(x3)
	{
		cout << "����A" << endl;
	}
	void show() { cout << "A::i= " << i << " A::c= " << c << " A::s= " << s << endl; }

};


class B : public virtual A
{
public:
	int i;	char c;  string s;
	B(int tempi, char tempc, string temps) : i(tempi), c(tempc), s(temps), A(tempi, tempc, temps)
	{
		cout << "����B" << endl;
	}
	void show() { cout << "B::i= " << i << " B::c= " << c << " B::s= " << s << endl; }
};


class C : public virtual A
{
public:
	int i;	char c;  string s;
	C(int tempi, char tempc, string temps) :i(tempi), c(tempc), s(temps), A(tempi, tempc, temps)
	{
		cout << "����C" << endl;
	}
	void show() { cout << "C::i= " << i << " C::c= " << c << " C::s= " << s << endl; }
};


class D : public  B, public  C
{
public:
	D(int tempai, char tempac, string tempas, int tempbi, char tempbc, string tempbs)
		:A(tempbi, tempbc, tempbs), B(tempai, tempac, tempas), C(tempai, tempac, tempas)
		/*
		����A B C�Ĺ��캯��˳����Σ������ȵ���A�Ĺ��캯����
		����̳е����֮�°���A��ֱֵ����D�๹�죬����B C���������ˡ�
		����A��ֵֻ��D�и�����ֵ�йأ���B C������ֵ�޹ء�
		��Ϊ����̳е����֮�£�Aֻ��һ������������������������
		���B��C��û���Լ������ݳ�Ա��B C�Ĺ��캯������û�����ã�������A�д���ֵ
		��� B C�����Լ������ݳ�Ա��B C�ͻ�ֻ���Լ������ݳ�Ա���ݱ�Ҫ��ֵ��
		ֻ��һ������������̳еı��ʣ���̳е���Ĺ���ֱ�������յ�ʵ������D�ฺ��

		��ֻ��һ��ͼֽ���̳п��Ա��������Ŀɿڿ��������й��������Լ������Ļ������п����Լ������ġ�����̳�һ����
		*/
	{
		cout << "����D" << endl;
	}
};


int main()
{
	D d(97, 'b', "bs", 100, 'c', "cs");
	d.A::show();
	cout << endl;
	d.B::show();
	cout << endl;
	d.C::show();
	cout << endl;
	cout << "ʹ����̳й�����·��������ʱ�������������ռ�ռ��СΪ��" << sizeof(d) << endl;
}

