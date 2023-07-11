#include<iostream>
using namespace std;
void swap(int& a, int& b)
{
    int c = a;
    a = b;
    b = c;
}


void input(int*& L)
{
    int i = 0;
    for (i = 0; i < 8; i++)
    {
        cin >> *(L + i);
    }
}



// �ѵ�������������sΪ������������ΪС����
void HeapAdjust(int* L, int s, int m)
{
    // ���浱ǰ���ڵ��ֵ
    int cr = L[s];
    // �����ӽڵ㿪ʼ����
    for (int i = 2 * s + 1; i <= m; i = 2 * i + 1)
    {
        // �ҳ������ӽڵ���ֵ��С�Ľڵ�
        if (i < m && L[i] > L[i + 1]) i++;
        // �����ǰ���ڵ��Ѿ�С�ڵ����ӽڵ㣬������ѭ��
        if (cr <= L[i]) break;
        // ���ӽڵ�����
        L[s] = L[i];
        // ���µ�ǰ���ڵ��λ��
        s = i;
    }
    // ��ԭ���ĸ��ڵ�ŵ��µ�λ����
    L[s] = cr;
}



// ��������
void HeapSort(int* L, int len)
{
    // ������ʼ��
    for (int i = len / 2 - 1; i >= 0; i--) // �����һ����Ҷ�ӽڵ㿪ʼ������
        HeapAdjust(L, i, len - 1); // �����ѽṹ
    // ���Ѷ�Ԫ����ѵ�Ԫ�ؽ����������µ�����
    for (int i = len - 1; i >= 0; i--) // �ѵĴ�Сÿ�μ�1
    {
        cout << *(L) << " "; // ����Ѷ�Ԫ��
        if (i) // ���ѵĴ�С��Ϊ0ʱ�����н����͵�����
        {
            swap(L[0], L[i]); // ���Ѷ�Ԫ����ѵ�Ԫ�ؽ���
            HeapAdjust(L, 0, i - 1); // �����ѽṹ
        }
    }
}




void output(int*& L)
{
    int i = 0;
    for (i = 0; i < 8; i++)
    {
        cout << *(L + i) << " ";
    }
    cout << endl;
}




int main()
{
    int* L = new int[8];
    input(L);
    HeapSort(L, 8);
    cout << endl;
}