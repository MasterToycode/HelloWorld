#include <iostream>
#include <string>
using namespace std;
class A
{
public:
	int i;	char c;  string s;

	A() : i(0), c('\0'), s("") { cout << "wucan构造A" << endl; }
	A(int x1, char x2, string x3) :i(x1), c(x2), s(x3)
	{
		cout << "构造A" << endl;
	}
	void show() { cout << "A::i= " << i << " A::c= " << c << " A::s= " << s << endl; }

};


class B : public virtual A
{
public:
	int i;	char c;  string s;
	B(int tempi, char tempc, string temps) : i(tempi), c(tempc), s(temps), A(tempi, tempc, temps)
	{
		cout << "构造B" << endl;
	}
	void show() { cout << "B::i= " << i << " B::c= " << c << " B::s= " << s << endl; }
};


class C : public virtual A
{
public:
	int i;	char c;  string s;
	C(int tempi, char tempc, string temps) :i(tempi), c(tempc), s(temps), A(tempi, tempc, temps)
	{
		cout << "构造C" << endl;
	}
	void show() { cout << "C::i= " << i << " C::c= " << c << " C::s= " << s << endl; }
};


class D : public  B, public  C
{
public:
	D(int tempai, char tempac, string tempas, int tempbi, char tempbc, string tempbs)
		:A(tempbi, tempbc, tempbs), B(tempai, tempac, tempas), C(tempai, tempac, tempas)
		/*
		无论A B C的构造函数顺序如何，总是先调用A的构造函数！
		在虚继承的情况之下啊，A的值直接由D类构造，不由B C类来构造了。
		所以A的值只和D中给他的值有关，和B C给他的值无关。
		因为在虚继承的情况之下，A只有一个副本，不再有两个副本！
		如果B，C中没有自己的数据成员，B C的构造函数几乎没有作用，不会向A中传递值
		如果 B C中有自己的数据成员！B C就会只向自己的数据成员传递必要的值！
		只有一个副本就是虚继承的本质！虚继承的类的构造直接由最终的实例化的D类负责！

		类只是一张图纸，继承可以比作美国的可口可乐引入中国，我们自己在他的基础上有开发自己本土的。就像继承一样。
		*/
	{
		cout << "构造D" << endl;
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
	cout << "使用虚继承规则解决路径二义性时，派生类对象所占空间大小为：" << sizeof(d) << endl;
}

