#include<iostream>
using namespace std;
void input(int*& L)
{
    int i = 0;
    for (i = 1; i < 9; i++)
    {
        cin >> *(L + i);
    }
}






void output(int*& L)
{
    int i = 0;
    for (i = 1; i < 9; i++)
    {
        cout << *(L + i) << " ";
    }
    cout << endl;
}






void COUNTING_SORT(int*& L, int*& C) //�������������
{
    int i = 0;
    int* A = new int[98]; //����������飬�±�ΪԪ��ֵ��1����ΪԪ��ֵ��СΪ1���������±��0��ʼ
    for (int i = 0; i < 98; i++) //��ʼ����������Ϊ0
    {
        *(A + i) = 0;
    }
    for (i = 1; i < 9; i++)
    {
        *(A + *(L + i)) = *(A + *(L + i)) + 1; //��Ԫ��ֵ���ִ�����¼������������
    }//���ڵĸ������鱣�����A[L[i]]�����ŵ���L[i]��Ԫ�صĸ���
    for (i = 1; i < 98; i++) //����ÿ��Ԫ��ֵ��������������е�λ��
    {
        *(A + i) = *(A + i) + *(A + i - 1);
    }//���ڵĸ������鱣�����A[L[i]]������С�ڵ���L[i]��Ԫ�صĸ���
    for (i = 8; i >= 1; i--) //��Ԫ�ذ��ռ��������м�¼��λ�÷������������
    {
        *(C + *(A + *(L + i))) = *(L + i);
        *(A + *(L + i)) = *(A + *(L + i)) - 1;
    }
}//��Ҫע����ǣ������������Ŀռ���Ҫ��һ���������������У���һ��λ��û��ʹ�á�





int main()
{
    int* L = new int[9];
    input(L);
    int* A = new int[9];
    COUNTING_SORT(L, A);
    output(A);
    cout << endl;
}