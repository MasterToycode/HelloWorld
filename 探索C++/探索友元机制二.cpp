#include <iostream>
class FriendClass;
class MyClass;
using namespace std;
// 定义 FriendClass 类
class FriendClass
{
private:
    int privateData;
public:
    FriendClass(int data) : privateData(data) {}

    // 友元成员函数声明，注意参数的类型是 MyClass
    void friendMemberFunction(const MyClass& obj);

    // FriendClass 的友元函数的声明
    friend void friendFunction(const FriendClass& obj);
};




// FriendClass 的友元函数定义
void friendFunction(const FriendClass& obj)
{
    cout << "Friend Function accessing FriendClass privateData: " << obj.privateData << endl << endl;
}



// 定义 MyClass 类
class MyClass
{
private:
    int privateData;

public:
    MyClass(int data) : privateData(data) {}

    // MyClass 的友元函数声明
    friend void friendFunction(const MyClass& obj);

    // 友元类声明
    friend class FriendClass;

    // 友元成员函数的定义，注意要加上类名 FriendClass::
    friend void FriendClass::friendMemberFunction(const MyClass& obj);
};




// MyClass 的友元函数定义
void friendFunction(const MyClass& obj)
{
    cout << "Friend Function accessing privateData: " << obj.privateData << endl << endl;
}




// 友元成员函数的定义，注意要加上类名 FriendClass::
void FriendClass::friendMemberFunction(const MyClass& obj)
{
    cout << "Friend Member Function accessing MyClass privateData: " << obj.privateData << endl << endl;
}






int main() {
    MyClass myObject(42);
    FriendClass friendObject(99);

    cout << "调用友元函数访问Myclass" << endl << endl;
    friendFunction(myObject);

    cout << "调用友元函数访问friendclass" << endl << endl;
    friendFunction(friendObject);

    cout << "调用 FriendClass 的友元成员函数访问Mycalss" << endl << endl;
    friendObject.friendMemberFunction(myObject);

    return 0;
}
