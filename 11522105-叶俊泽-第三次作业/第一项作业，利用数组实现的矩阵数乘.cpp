#include<iostream>
#include <iomanip> //用于输出格式控制的库
using namespace std;
void fun2(int*& M, int n1, int n2) //n1,n2为矩阵的行数和列数，M为指向矩阵的指针
{
    cout << "Please input the number that the Matrix will multipy:"; //提示用户输入乘数
    int number;
    cin >> number;
    for (int i = 0; i < n1 * n2; i++) //遍历矩阵中的每一个元素
    {
        M[i] = M[i] * number; //将元素乘上用户输入的乘数
        cout << setw(3) << M[i] << right; //输出格式控制：每个元素占3个字符宽度，右对齐
        if ((i + 1) % n2 == 0)cout << endl; //每输出完一行就换行
    }
}

void fun1(int n1, int n2)
{
    cout << "Please input the elements of the Matrix:"; //提示用户输入矩阵元素
    int* M = new int[n1 * n2]; //动态分配一维数组，用于存放矩阵元素
    for (int i = 0; i < n1 * n2; i++) //遍历数组，输入元素
    {
        int temp;
        cin >> temp;
        M[i] = temp;
        cout << setw(3) << M[i] << right; //输出格式控制：每个元素占3个字符宽度，右对齐
        if ((i + 1) % n2 == 0)cout << endl; //每输出完一行就换行
    }
    fun2(M, n1, n2); //调用fun2函数，对矩阵进行乘法运算
}



int main()
{
    int n1, n2;
    cout << "Please input the dimension of the Matrix:"; //提示用户输入矩阵的行数和列数
    cin >> n1 >> n2;
    cout << endl;
    fun1(n1, n2); //调用fun1函数，输入矩阵元素并进行乘法运算
}