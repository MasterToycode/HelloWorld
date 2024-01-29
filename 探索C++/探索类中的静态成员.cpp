#include <iostream>
using namespace std;
class MyClass
{
public:
    // 静态成员变量
    static int staticVariable;

    // 普通成员变量
    int normalVariable;

    // 构造函数
    MyClass(int value) : normalVariable(value) {
        // 静态成员变量在构造函数中初始化
        staticVariable = 0;
    }

    // 静态成员函数
    static void staticFunction() {
        // 静态成员函数可以访问静态成员变量，但不能直接访问普通成员变量
        std::cout << "Static Function: " << staticVariable << std::endl;
    }

    // 普通成员函数
    void normalFunction() {
        // 普通成员函数可以访问静态成员变量和普通成员变量
        std::cout << "Normal Function: " << staticVariable << ", " << normalVariable << std::endl;
    }
};

// 初始化静态成员变量
int MyClass::staticVariable = 100;

int main() {
    // 创建类的对象
    MyClass obj1(42);
    std::cout << std::endl;
    MyClass obj2(87);
    cout << endl;


    // 调用静态成员函数
    MyClass::staticFunction(); // 输出：Static Function: 0

    // 调用普通成员函数
    obj1.normalFunction(); // 输出：Normal Function: 0, 42
    obj2.normalFunction(); // 输出：Normal Function: 0, 87

    // 修改静态成员变量
    MyClass::staticVariable = 200;

    // 再次调用静态成员函数和普通成员函数
    MyClass::staticFunction(); // 输出：Static Function: 200
    obj1.normalFunction(); // 输出：Normal Function: 200, 42
    obj2.normalFunction(); // 输出：Normal Function: 200, 87

    return 0;
}
