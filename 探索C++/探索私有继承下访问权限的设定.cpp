#include <iostream>
using namespace std;
class Base
{
public:
    int publicMember;
    void publicFunction()
    {
        cout << "Base 的公有成员函数: " << publicMember << endl;
    }

private:
    int privateMember;
    void privateFunction()
    {
        cout << "Base 的私有成员函数 " << privateMember << endl;
    }


protected:
    int protectedMember;
    void protectedFunction()
    {
        cout << "Base 的保护成员函数 " << protectedMember << endl;
    }
    Base() :publicMember(1), protectedMember(2), privateMember(3) {}
};




// 私有派生类
class Derived : private Base
{
public:
    using Base::publicMember;        // 访问声明，将基类的公有成员在派生类中引入
    using Base::publicFunction;     // 访问声明，将基类的公有成员在派生类中引入
    using Base::protectedMember;
    using Base::protectedFunction;

    /*
    访问声明只能调整基类的保护成员和公有成员在派生类中的访问域，
    不能改变基类的私有成员在派生类中的访问域，这样可以保护封装性
    */

    void accessBaseMembers()
    {
        cout << "Derived 中访问基类的公有成员：" << publicMember << endl;
        cout << "Derived 中访问基类的保护成员：" << protectedMember << endl;
        publicFunction();
        protectedFunction();
    }
    Derived() :Base() {}
};


int main()
{
    Derived derivedObj;
    derivedObj.accessBaseMembers();
    cout << endl;

    cout << endl
        << "在类外访问基类的公有成员" << endl
        << derivedObj.publicMember << endl << endl;

    cout << "在类外访问基类的保护成员"
        << derivedObj.protectedMember << endl << endl;

    return 0;
}
/*
通过使用 using 关键字和访问声明，
你在私有继承的情况下允许了对基类的公有成员和公有成员函数的访问。
这样，虽然派生类 Derived 是私有继承自 Base，
但通过访问声明，你在派生类的外部（比如 main 函数中）仍然能够访问基类的公有成员和公有成员函数。
*/


/*
对重载函数的访问声明将调整基类中具有该名字的所有函数的访问域。
若基类中的这些重载函数处在不同的访问域，则在派生类中不能调整其访问域
*/