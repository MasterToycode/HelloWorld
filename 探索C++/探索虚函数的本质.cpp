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
	A a;//虽然A的构造函数中存在f函数，但是C++中的构造函数不存在多态性！
	cout << endl;
	B b;//这里在构造B的时候，相应的构造函数只会输出自己对应的f函数！

	cout << endl;
	A* p = &b;
	a.f();//直接调用A自己的f函数
	b.f();//直接调用B自己的f函数
	b.g();//直接调用B自己的g函数
	a.g();//直接调用a自己的g函数

	cout << endl;
	b.h();//因为B没有定义h函数
	//调用A的h函数，这里的和函数再间接调用B修改过的虚函数f，调用A的g函数。因为g不是虚函数
	a.h();//直接调用A的h函数，再间接调用A自己的f，g函数

	cout << endl;
	p->f();//虽然指针p的类型是A类，但是f是虚函数，p可以调用B中的修改过的f函数
	p->g();//p指向了B类，但是p的类型是A，而且g不是虚函数，所以只能调用B中的A类的g函数
	p->h();//这个同b.h()是一样的效果
	//构造函数是确定的，不存在多态性！！！
}