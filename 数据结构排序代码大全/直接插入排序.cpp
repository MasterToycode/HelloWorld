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



// ���������㷨
void Insertsort(int*& L)
{
	// �ӵڶ���Ԫ�ؿ�ʼ����
	for (int i = 1; i < 8; i++)
	{
		// ȡ����ǰ��������Ԫ��
		int end = *(L + i);
		// �ӵ�ǰԪ�ص�ǰһ��Ԫ�ؿ�ʼ����
		int key = i - 1;
		// �����ǰԪ��С��ǰһ��Ԫ�أ���ǰһ��Ԫ�غ���һλ
		while (key >= 0 && *(L + key) > end)
		{
			*(L + key + 1) = *(L + key);
			key--;
		}
		// ����ǰԪ�ز��뵽���ʵ�λ��
		*(L + key + 1) = end;
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