#include <iostream>
#include <iomanip> 
#include<string>
using namespace std;
int main()
{
    /*
    // 设置 skipws 标志，从流中提取数据时跳过空白字符
    cout << "请输入一个整数（跳过空白字符）：";
    cin >> skipws;  // 设置 skipws 标志
    string number1;
    cin >> number1;
    cout << "你输入的数据是：" << number1 << endl;
    cout << setw(10) << setfill('*') << right << "Right Aligned" << endl;
    cout << setw(10) << setfill('*') << left << "Left Aligned" << endl;


    // 使用对齐标志 internal，符号左对齐，数据右对齐输出
    int negativeNumber = -12345;
    cout << setw(15) << setfill(' ') << internal << negativeNumber << endl;


    int number = 255;
    cout << "默认输出（十进制）: " << number << endl;
    cout << "八进制输出: " << oct << showbase << showpos << showpoint << number << endl;
    cout << "十六进制输出: " <<hex<<uppercase<< number << endl;
    cout << "恢复十进制输出: " << dec<< number << endl<<endl;
    */



    double number2 = 123456.789;
    cout << "默认输出: " << number2 << endl;
    cout << "科学计数法输出: " << scientific << number2 << endl;
    cout << "定点表示法输出: " << fixed << number2 << endl;
    cout.unsetf(ios::scientific | ios::fixed);
    cout << "恢复默认输出: " << number2 << endl << endl;





    cout << "请输入文本，每遇到一个逗号结束输入：" << std::endl;
    string inputText;
    // 使用 std::getline 读取一行文本，直到遇到逗号为止
    getline(cin, inputText, ',');
    cout << "读取到的文本是：" << inputText << std::endl;


    return 0;
}
