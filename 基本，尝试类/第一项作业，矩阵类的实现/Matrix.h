#include<iostream>
#include<string>
#include <iomanip>
using namespace std;

class Matrix
{
    private:
        int n1, n2;
        int** M;
    public:
        // 构造函数接收矩阵的维度作为参数
        Matrix(int t1, int t2) : n1(t1), n2(t2)
        {
            M = nullptr; // 初始化M为nullptr
        }
        // 析构函数用于释放分配的内存
        ~Matrix()
        {
            if (M != nullptr)
            {
                for (int i = 0; i < n1; i++)
                {
                    delete[] M[i];
                }
                delete[] M;
            }
        }
    void InitializeMatrix();
    void OutPut();
    void Modify(int n1, int n2);
    void Multiply();
    void rotate90DegreesClockwise();
    void Rotate90DegreesClockwise();
};



// 成员函数用于分配矩阵内存和输入矩阵元素
void Matrix::InitializeMatrix()
{
    cout << "Please input the elements of the Matrix:"; // 提示用户输入矩阵元素
    M = new int* [n1]; // 动态分配二维数组，用于存放矩阵元素
    for (int i = 0; i < n1; i++)
    {
        M[i] = new int[n2]; // 为每一行分配内存
        for (int j = 0; j < n2; j++) // 遍历数组，输入元素
        {
            cin >> M[i][j];
            cout << setw(3) << M[i][j] << right; // 输出格式控制：每个元素占3个字符宽度，右对齐
        }
        cout << endl; // 每输出完一行就换行
    }
}



void Matrix::OutPut()
{
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            cout << setw(3) << M[i][j] << right; // 输出格式控制：每个元素占3个字符宽度，右对齐
        }
        cout << endl; // 每输出完一行就换行
    }
}

void Matrix::Multiply()
{
    cout << "Please input the number that the Matrix will multipy:"; //提示用户输入乘数
    int number;
    cin >> number;
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            M[i][j] *= number;
            cout << setw(3) << M[i][j] << right; // 输出格式控制：每个元素占3个字符宽度，右对齐
        }
        cout << endl; // 每输出完一行就换行
    }
}

void Matrix::rotate90DegreesClockwise()
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

void Matrix::Rotate90DegreesClockwise()
{
    int angle;
    cout << "请输入旋转角度（必须是90度的倍数）："; // 提示用户输入旋转角度
    cin >> angle;
    while (1) {
        if (angle % 90 != 0 || angle < 0 || angle >= 360) // 检查角度是否是90的倍数且在有效范围内
        {
            cout << "旋转角度必须是90度的倍数且在0到360度之间。请重新输入:";
            cin >> angle;
            cout << endl;
        }
        else break;
    }
    int rotations = angle / 90; // 计算需要旋转的次数

    while (rotations > 0)
    {
        Matrix::rotate90DegreesClockwise();
        rotations--;
    }
}

