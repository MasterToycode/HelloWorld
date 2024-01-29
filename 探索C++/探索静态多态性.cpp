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
����������������У���̬����ָͬһ��Ϣ�����ڲ�ͬ����ʱ������ͬ��Ϊ�����ԡ�
�������Ϣ��Ҫ��ָ����ĳ�Ա�����ĵ��ã���Ϊ��Ҫ��ָ��ĳ�Ա�����Ĺ��ܱ��֡�
��̬�Է�Ϊ���֣�����ʱ��̬�Ժ�����ʱ��̬��
*/