#include<iostream>
#include<cmath>
using namespace std;
bool isNarcissistic(int num) //判断是否为水仙花数的函数
{
    int originalNum = num; //保留原始值
    int numDigits = (int)log10(num) + 1; //确定数字的位数
    int sum = 0; //用于存储每个位数上数字的 numDigits 次方的和
    while (num > 0) //循环遍历每个数字
    {
        int digit = num % 10; //取出 num 的每个位数上的位数
        sum += pow(digit, numDigits); //将该位数上数字的 numDigits 次方加入 sum
        num /= 10; 
    }
    return sum == originalNum; //若 sum 等于原始值，则返回真，否则返回假
}

int main()
{
    cout << "请您输入数字" << endl;
    int num;
    cin >> num;
    if (isNarcissistic(num))
        cout << num << "是水仙花数" << endl;
    else
        cout << num << "不是水仙花数" << endl;
    return 0;
}
