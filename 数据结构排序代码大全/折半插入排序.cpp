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


//���������㷨
void Insertsort(int*& L)
{
    int i = 0;
    //�ӵڶ�������ʼ����
    for (i = 1; i < 8; i++)
    {
        int end = *(L + i); //��ȡ��ǰҪ�������
        int low = 0;
        int high = i - 1;
        //ʹ�ö��ֲ��ҷ����ҵ�����λ��
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (*(L + mid) > end)high = mid - 1; //����м�ֵ���ڵ�ǰ��������С��������
            else low = mid + 1; //˵�����ϰ���
        }//��high<lowʱ��˵������λ����low����
        //������λ�ú����������һλ
        for (int j = i - 1; j >= high + 1; j--)
        {
            *(L + j + 1) = *(L + j);
        }
        //����ǰ�����뵽��Ӧλ��
        *(L + high + 1) = end;
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
    Insertsort(L);
    ouput(L);
}