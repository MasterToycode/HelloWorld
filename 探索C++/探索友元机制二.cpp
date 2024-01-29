#include <iostream>
class FriendClass;
class MyClass;
using namespace std;
// ���� FriendClass ��
class FriendClass
{
private:
    int privateData;
public:
    FriendClass(int data) : privateData(data) {}

    // ��Ԫ��Ա����������ע������������� MyClass
    void friendMemberFunction(const MyClass& obj);

    // FriendClass ����Ԫ����������
    friend void friendFunction(const FriendClass& obj);
};




// FriendClass ����Ԫ��������
void friendFunction(const FriendClass& obj)
{
    cout << "Friend Function accessing FriendClass privateData: " << obj.privateData << endl << endl;
}



// ���� MyClass ��
class MyClass
{
private:
    int privateData;

public:
    MyClass(int data) : privateData(data) {}

    // MyClass ����Ԫ��������
    friend void friendFunction(const MyClass& obj);

    // ��Ԫ������
    friend class FriendClass;

    // ��Ԫ��Ա�����Ķ��壬ע��Ҫ�������� FriendClass::
    friend void FriendClass::friendMemberFunction(const MyClass& obj);
};




// MyClass ����Ԫ��������
void friendFunction(const MyClass& obj)
{
    cout << "Friend Function accessing privateData: " << obj.privateData << endl << endl;
}




// ��Ԫ��Ա�����Ķ��壬ע��Ҫ�������� FriendClass::
void FriendClass::friendMemberFunction(const MyClass& obj)
{
    cout << "Friend Member Function accessing MyClass privateData: " << obj.privateData << endl << endl;
}






int main() {
    MyClass myObject(42);
    FriendClass friendObject(99);

    cout << "������Ԫ��������Myclass" << endl << endl;
    friendFunction(myObject);

    cout << "������Ԫ��������friendclass" << endl << endl;
    friendFunction(friendObject);

    cout << "���� FriendClass ����Ԫ��Ա��������Mycalss" << endl << endl;
    friendObject.friendMemberFunction(myObject);

    return 0;
}
