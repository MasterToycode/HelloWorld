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


//ѡ������ÿ���ҵ�δ������������С��Ԫ�أ��ŵ����������е�ĩβ
int SelectMinkey(int* L, int n)//ѡ��δ������������С��Ԫ�ص��±�
{
    int key = n;
    for (int i = n + 1; i < 7; i++)
    {
        if (L[key] > L[i])
            key = i;
    }
    return key;
}



void SelectionSort(int* L)//ѡ������
{
    for (int i = 0; i < 6; i++)
    {
        int j = SelectMinkey(L, i);//�ҵ�δ������������СԪ�ص��±�
        if (i != j)//���δ������������СԪ�ز������������е�ĩβ���򽻻����ǵ�λ��
        {
            int temp = L[i];
            L[i] = L[j];
            L[j] = temp;
        }
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
    SelectionSort(L);
    ouput(L);
}