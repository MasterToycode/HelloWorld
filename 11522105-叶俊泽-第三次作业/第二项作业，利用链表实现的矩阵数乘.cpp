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
    cout << "Please input the number that the Matrix will multipy:"; //��ʾ�û��������
    int number;
    cin >> number;
    Matrix* r = M->next;
    for (int i = 0; r != NULL && i < n1 * n2; r = r->next, i++)
    {
        r->p = r->p * number;
        cout << setw(3) << r->p << right; //�����ʽ���ƣ�ÿ��Ԫ��ռ3���ַ���ȣ��Ҷ���
        if ((i + 1) % n2 == 0)cout << endl; //ÿ�����һ�оͻ���
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
        cout << setw(3) << temp << right; //�����ʽ���ƣ�ÿ��Ԫ��ռ3���ַ���ȣ��Ҷ���
        if ((i + 1) % n2 == 0)cout << endl; //ÿ�����һ�оͻ���
        myma->next = r->next;
        r->next = myma;
        r = myma;
    }
    fun(M, n1, n2);
}



int main()
{
    int n1, n2;
    cout << "Please input the dimension of the Matrix:"; //��ʾ�û�������������������
    cin >> n1 >> n2;
    cout << endl;
    Matrix* M;
    M = new Matrix;
    M->next = NULL;
    Creat(M, n1, n2);
}