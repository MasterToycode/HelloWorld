
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
    ��ֵ���������operator =()�ķ���ֵ�����Ƕ�������ö����Ƕ���
    ��Ϊ��ֵ���ʽ����ֵ�����������ص������������ߡ�
    ������ֵ������Ϊ��������ã��ܹ��ı�����ֵ��������ֵ���������Ϊ����
    ��������Ƕ����ֵ�����Ƕ�����ڴ�ռ䣬��ֵ������������Ϊ��ֵ����������
    Υ���ˡ�=����ԭ�й�������
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
��ֵ�����ֻ������Ϊ�Ǿ�̬��Ա����������������Ԫ����
��ֵ��������غ�����Ψһһ�����ܱ��̳е���������غ���
*/