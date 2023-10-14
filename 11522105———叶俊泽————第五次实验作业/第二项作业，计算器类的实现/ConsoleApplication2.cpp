#include"calculator.h"
void printHorizontalLine()
{
    string horizontalLine(50, '-');
    cout << horizontalLine << endl;
}

void Explantion() 
{
    cout << "您好，欢迎使用计算器类！关于此类说明如下：" << endl
        << "此类定义了加，减，乘，除，取余，乘方六种运算！" << endl
        << "请您正确输入+，-，*,/,%,^进行运算并且符合有关的数学基本规则！" << endl;
}

int main() {
    Explantion();
    char choice;
    do
    {
        double x, y;
        char z;
        cout << "请输入操作数1: ";
        cin >> x;
        cout << endl;
        cout << "请输入操作数2: ";
        cin >> y;
        cout << endl;
        cout << "请输入操作符号: ";
        cin >> z;
        cout << endl;
        calculator opreta(x,y,z);
        if (opreta.opearation(x, y, z) != 0)
        {
            cout << "运算结果为：" << x << " " << z << " " << y << " " << "=" << opreta.opearation(x, y, z) << endl;
        }
        printHorizontalLine();
        cout << "是否继续操作？(y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');
}