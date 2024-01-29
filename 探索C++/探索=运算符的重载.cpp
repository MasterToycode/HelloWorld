
#include <iostream>
using namespace std;
class MyNumber
{
private:
    int value;
public:
    MyNumber(int val = 0) : value(val) {}

    MyNumber& operator=(const MyNumber& other)
    {
        if (this != &other)
        {
            value = other.value;
        }
        return *this;
    }


    /*
    赋值运算符函数operator =()的返回值类型是对象的引用而不是对象。
    因为赋值表达式是左值函数，即返回的是运算符的左边。
    将返回值类型设为对象的引用，能够改变对象的值，而返回值类型如果设为对象，
    则操作的是对象的值而不是对象的内存空间，赋值操作后不能再作为左值继续操作，
    违背了“=”的原有功能语义
    */


    void print() const
    {
        cout << "Value: " << value << endl;
    }
};



int main()
{

    MyNumber num1(42);
    MyNumber num2(99);

    cout << "Before using the '=' :" << endl;
    num1.print();
    num2.print();

    num1 = num2 = MyNumber(77);


    cout << "After assignment:" << endl;
    cout << "num1: ";
    num1.print();
    cout << "num2: ";
    num2.print();

    return 0;
}

/*
赋值运算符只能重载为非静态成员函数，而不能是友元函数
赋值运算符重载函数是唯一一个不能被继承的运算符重载函数
*/