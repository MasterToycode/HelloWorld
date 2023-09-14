#include<iostream>
#include<iomanip>
using namespace std;

typedef struct my
{
    int p;
    struct my* next;
}Matrix;


void fun(Matrix*& M, int n1, int n2)
{
    cout << "Please input the number that the Matrix will multipy:"; //提示用户输入乘数
    int number;
    cin >> number;
    Matrix* r = M->next;
    for (int i = 0; r != NULL && i < n1 * n2; r = r->next, i++)
    {
        r->p = r->p * number;
        cout << setw(3) << r->p << right; //输出格式控制：每个元素占3个字符宽度，右对齐
        if ((i + 1) % n2 == 0)cout << endl; //每输出完一行就换行
    }
}




void Creat(Matrix*& M, int n1, int n2)
{
    Matrix* r = M;
    cout << "Please input the elements of the Matrix:";
    for (int i = 0; i < n1 * n2; i++)
    {
        int temp;
        cin >> temp;
        Matrix* myma = new Matrix;
        myma->p = temp;
        cout << setw(3) << temp << right; //输出格式控制：每个元素占3个字符宽度，右对齐
        if ((i + 1) % n2 == 0)cout << endl; //每输出完一行就换行
        myma->next = r->next;
        r->next = myma;
        r = myma;
    }
    fun(M, n1, n2);
}



int main()
{
    int n1, n2;
    cout << "Please input the dimension of the Matrix:"; //提示用户输入矩阵的行数和列数
    cin >> n1 >> n2;
    cout << endl;
    Matrix* M;
    M = new Matrix;
    M->next = NULL;
    Creat(M, n1, n2);
}