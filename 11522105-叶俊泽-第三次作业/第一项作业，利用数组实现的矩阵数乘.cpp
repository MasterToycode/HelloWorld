#include<iostream>
#include <iomanip> //���������ʽ���ƵĿ�
using namespace std;
void fun2(int*& M, int n1, int n2) //n1,n2Ϊ�����������������MΪָ������ָ��
{
    cout << "Please input the number that the Matrix will multipy:"; //��ʾ�û��������
    int number;
    cin >> number;
    for (int i = 0; i < n1 * n2; i++) //���������е�ÿһ��Ԫ��
    {
        M[i] = M[i] * number; //��Ԫ�س����û�����ĳ���
        cout << setw(3) << M[i] << right; //�����ʽ���ƣ�ÿ��Ԫ��ռ3���ַ���ȣ��Ҷ���
        if ((i + 1) % n2 == 0)cout << endl; //ÿ�����һ�оͻ���
    }
}

void fun1(int n1, int n2)
{
    cout << "Please input the elements of the Matrix:"; //��ʾ�û��������Ԫ��
    int* M = new int[n1 * n2]; //��̬����һά���飬���ڴ�ž���Ԫ��
    for (int i = 0; i < n1 * n2; i++) //�������飬����Ԫ��
    {
        int temp;
        cin >> temp;
        M[i] = temp;
        cout << setw(3) << M[i] << right; //�����ʽ���ƣ�ÿ��Ԫ��ռ3���ַ���ȣ��Ҷ���
        if ((i + 1) % n2 == 0)cout << endl; //ÿ�����һ�оͻ���
    }
    fun2(M, n1, n2); //����fun2�������Ծ�����г˷�����
}



int main()
{
    int n1, n2;
    cout << "Please input the dimension of the Matrix:"; //��ʾ�û�������������������
    cin >> n1 >> n2;
    cout << endl;
    fun1(n1, n2); //����fun1�������������Ԫ�ز����г˷�����
}