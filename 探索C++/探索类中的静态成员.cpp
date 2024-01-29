#include <iostream>
using namespace std;
class MyClass
{
public:
    // ��̬��Ա����
    static int staticVariable;

    // ��ͨ��Ա����
    int normalVariable;

    // ���캯��
    MyClass(int value) : normalVariable(value) {
        // ��̬��Ա�����ڹ��캯���г�ʼ��
        staticVariable = 0;
    }

    // ��̬��Ա����
    static void staticFunction() {
        // ��̬��Ա�������Է��ʾ�̬��Ա������������ֱ�ӷ�����ͨ��Ա����
        std::cout << "Static Function: " << staticVariable << std::endl;
    }

    // ��ͨ��Ա����
    void normalFunction() {
        // ��ͨ��Ա�������Է��ʾ�̬��Ա��������ͨ��Ա����
        std::cout << "Normal Function: " << staticVariable << ", " << normalVariable << std::endl;
    }
};

// ��ʼ����̬��Ա����
int MyClass::staticVariable = 100;

int main() {
    // ������Ķ���
    MyClass obj1(42);
    std::cout << std::endl;
    MyClass obj2(87);
    cout << endl;


    // ���þ�̬��Ա����
    MyClass::staticFunction(); // �����Static Function: 0

    // ������ͨ��Ա����
    obj1.normalFunction(); // �����Normal Function: 0, 42
    obj2.normalFunction(); // �����Normal Function: 0, 87

    // �޸ľ�̬��Ա����
    MyClass::staticVariable = 200;

    // �ٴε��þ�̬��Ա��������ͨ��Ա����
    MyClass::staticFunction(); // �����Static Function: 200
    obj1.normalFunction(); // �����Normal Function: 200, 42
    obj2.normalFunction(); // �����Normal Function: 200, 87

    return 0;
}
