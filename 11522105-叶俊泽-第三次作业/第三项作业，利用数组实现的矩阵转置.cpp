#include <iostream>
#include <iomanip> // 用于输出格式控制的库
using namespace std;

void rotate90DegreesClockwise(int**& M, int& n1, int& n2)
{
    int** temp = new int* [n2]; // 创建临时二维数组
    for (int i = 0; i < n2; i++)
    {
        temp[i] = new int[n1];
    }

    // 顺时针旋转矩阵
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            temp[j][n1 - i - 1] = M[i][j];
        }
    }

    // 释放原矩阵内存
    for (int i = 0; i < n1; i++)
    {
        delete[] M[i];
    }
    delete[] M;

    // 更新行列数和矩阵指针
    swap(n1, n2);
    M = temp;
}

void fun2(int**& M, int n1, int n2, int angle) // n1,n2为矩阵的行数和列数，M为指向矩阵的指针，angle为旋转角度
{
    if (angle % 90 != 0 || angle < 0 || angle >= 360) // 检查角度是否是90的倍数且在有效范围内
    {
        cout << "旋转角度必须是90度的倍数且在0到360度之间。" << endl;
        return;
    }

    int rotations = angle / 90; // 计算需要旋转的次数

    while (rotations > 0)
    {
        rotate90DegreesClockwise(M, n1, n2);
        rotations--;
    }

    // 打印旋转后的矩阵
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            cout << setw(3) << M[i][j] << right; // 输出格式控制：每个元素占3个字符宽度，右对齐
        }
        cout << endl; // 每输出完一行就换行
    }
}

void fun1(int n1, int n2)
{
    cout << "Please input the elements of the Matrix:"; // 提示用户输入矩阵元素
    int** M = new int* [n1]; // 动态分配二维数组，用于存放矩阵元素
    for (int i = 0; i < n1; i++)
    {
        M[i] = new int[n2]; // 为每一行分配内存
        for (int j = 0; j < n2; j++) // 遍历数组，输入元素
        {
            int temp;
            cin >> temp;
            M[i][j] = temp;
            cout << setw(3) << M[i][j] << right; // 输出格式控制：每个元素占3个字符宽度，右对齐
        }
        cout << endl; // 每输出完一行就换行
    }

    int angle;
    cout << "请输入旋转角度（必须是90度的倍数）："; // 提示用户输入旋转角度
    cin >> angle;
    fun2(M, n1, n2, angle); // 调用fun2函数，对矩阵进行旋转
    for (int i = 0; i < n1; i++) // 释放分配的内存
    {
        delete[] M[i];
    }
    delete[] M;
}

int main()
{
    int n1, n2;
    cout << "Please input the dimension of the Matrix:"; // 提示用户输入矩阵的行数和列数
    cin >> n1 >> n2;
    cout << endl;
    fun1(n1, n2); // 调用fun1函数，输入矩阵元素并进行旋转
    return 0;
}
