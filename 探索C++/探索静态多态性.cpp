#include <iostream>
using namespace std;
class MyClass 
{
private:
    bool flag;
    int data[5];

public:
    MyClass(bool f = true) : flag(f) 
    {
        for (int i = 0; i < 5; ++i) 
        {
            data[i] = i + 1;
        }
    }


    bool operator!() const 
    {
        return !flag;
    }


    int& operator[](int index)
    {
        return data[index];
    }
};

int main() {
    MyClass obj;

    if (!obj)
    {
        cout << "Object is false." << std::endl;
    }
    else 
    {
        cout << "Object is true." << std::endl;
    }


    std::cout << "Value at index 2: " << obj[2] << std::endl;


    obj[2] = 99;


    std::cout << "Updated value at index 2: " << obj[2] << std::endl;

    return 0;
}




/*
在面向对象程序设计中，多态性是指同一消息作用于不同对象时产生不同行为的特性。
这里的消息主要是指对类的成员函数的调用，行为主要是指类的成员函数的功能表现。
多态性分为两种：编译时多态性和运行时多态性
*/