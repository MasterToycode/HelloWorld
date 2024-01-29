#include<iostream>
using namespace std;
// 函数返回一个引用
int& getReference() 
{
	static int x = 5;  // 使用 static 以避免返回局部变量的地址
	//请注意，使用引用返回值要小心，确保不返回指向局部变量的引用，
	return x;
}

int main()
{
	int num = 50;
	int& re = num;
	int& re1 = re;
	int* p = &num;
	cout << re << endl
		<< *p << endl
		<< num << endl;

	re1 = 100;
	cout << re << endl
		<< *p << endl
		<< num << endl << endl;

	cout << "以上是探索区分引用和指针" << endl << endl;



	// 函数调用作为左值
	getReference() = 10;

	// 获取引用并输出
	int& ref = getReference();
	cout << "Value of ref: " << ref << endl;

	cout << "以上是探索引用作为函数返回值" << endl << endl;




	int i = 10;
	int j = 20;

	// 声明引用并初始化
	int& ref1 = i;

	cout << "Initial value of i: " << i << endl;
	cout << "Value through ref: " << ref1 << endl;

	// 修改原始变量 i，引用也会反映这个变化
	i = 30;
	cout << "Modified value of i: " << i << endl;
	cout << "Value through ref: " << ref1 << endl;

	// ref = &j;  // 错误！引用不能重新关联到另一个对象
	// ref = j;   // 正确！修改了原始变量 i 的值，而不是引用关联的对象

	cout << "以上是探索引用一旦被初始化就不能再次被引用关联新的对象！" << endl;
}

