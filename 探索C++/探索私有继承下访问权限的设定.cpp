#include <iostream>
using namespace std;
class Base
{
public:
    int publicMember;
    void publicFunction()
    {
        cout << "Base �Ĺ��г�Ա����: " << publicMember << endl;
    }

private:
    int privateMember;
    void privateFunction()
    {
        cout << "Base ��˽�г�Ա���� " << privateMember << endl;
    }


protected:
    int protectedMember;
    void protectedFunction()
    {
        cout << "Base �ı�����Ա���� " << protectedMember << endl;
    }
    Base() :publicMember(1), protectedMember(2), privateMember(3) {}
};




// ˽��������
class Derived : private Base
{
public:
    using Base::publicMember;        // ����������������Ĺ��г�Ա��������������
    using Base::publicFunction;     // ����������������Ĺ��г�Ա��������������
    using Base::protectedMember;
    using Base::protectedFunction;

    /*
    ��������ֻ�ܵ�������ı�����Ա�͹��г�Ա���������еķ�����
    ���ܸı�����˽�г�Ա���������еķ������������Ա�����װ��
    */

    void accessBaseMembers()
    {
        cout << "Derived �з��ʻ���Ĺ��г�Ա��" << publicMember << endl;
        cout << "Derived �з��ʻ���ı�����Ա��" << protectedMember << endl;
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
        << "��������ʻ���Ĺ��г�Ա" << endl
        << derivedObj.publicMember << endl << endl;

    cout << "��������ʻ���ı�����Ա"
        << derivedObj.protectedMember << endl << endl;

    return 0;
}
/*
ͨ��ʹ�� using �ؼ��ֺͷ���������
����˽�м̳е�����������˶Ի���Ĺ��г�Ա�͹��г�Ա�����ķ��ʡ�
��������Ȼ������ Derived ��˽�м̳��� Base��
��ͨ������������������������ⲿ������ main �����У���Ȼ�ܹ����ʻ���Ĺ��г�Ա�͹��г�Ա������
*/


/*
�����غ����ķ������������������о��и����ֵ����к����ķ�����
�������е���Щ���غ������ڲ�ͬ�ķ����������������в��ܵ����������
*/