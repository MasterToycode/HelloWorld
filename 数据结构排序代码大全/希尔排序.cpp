#include<iostream>
using namespace std;

void input(int*& L)
{
    int i = 0;
    for (i = 0; i < 8; i++)
    {
        cin >> *(L + i);
    }
}

// ϣ�����򣬶�L����������a����Ϊ��������
void shellsort(int*& L, int dk)
{
    // �ӵ�dk��Ԫ�ؿ�ʼ�����β���ǰ���Ѿ��ź������������
    for (int i = dk; i < 8; i++)
    {
        int end = *(L + i); // ȡ����ǰԪ��
        int key = i - dk; // ��ȡ������λ��
        // ���������λ���������������У����Ҵ�����Ԫ�رȵ�ǰԪ�ش󣬾ͽ���ǰԪ�غ���
        while (key >= 0 && *(L + key) > end)
        {
            *(L + key + dk) = *(L + key); // ����ǰԪ�غ���
            key -= dk; // �ٴλ�ȡ������λ��
        }
        // ���뵱ǰԪ��
        *(L + key + dk) = end;
    }
}

// ϣ�����򣬶�L����������a����Ϊ��������
void ShellInsert(int*& L, int a[])
{
    int t = 0;
    // ������������
    for (t = 0; t < 4; t++)
    {
        shellsort(L, a[t]); // ��L����������a[t]Ϊ����
    }
}







void ouput(int*& L)
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
    int a[4] = { 5,3,2,1 };
    ShellInsert(L, a);
    ouput(L);
}