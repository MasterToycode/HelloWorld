#include <iostream>
using namespace std;

template<typename T1, typename T2, typename T3>
class OutPut
{
private:
    T1 data1;
    T2 data2;
    T3 data3;

public:
    OutPut(T1 x1, T2 x2, T3 x3) : data1(x1), data2(x2), data3(x3) {}

    void Display()
    {
        cout << "Data 1: " << data1 << endl
            << "Data 2: " << data2 << endl
            << "Data 3: " << data3 << endl;
    }

    void Display(T1 x1)
    {
        cout << "Using overloaded function to display data: " << x1 << endl;
    }
};

int main()
{
    // 实例化模板类，包含整型、浮点型、字符型和字符串等数据
    OutPut<int, double, char> instance1(10, 3.14, 'A');
    OutPut<string, float, int> instance2("Hello", 2.5f, 20);

    // 调用 Display 函数
    instance1.Display();
    instance1.Display(42);

    instance2.Display();
    instance2.Display("World");

    return 0;
}
