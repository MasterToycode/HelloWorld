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




// ��������ĺ����㷨�������з�Ϊ�����֣���߱����ĵ�С���ұ߱����ĵ��
int Quick_Sort(int*& L, int low, int high)
{
	// �Ե�һ��Ԫ��Ϊ���ĵ�
	int key = *(L + low);
	while (low < high)
	{
		// ���������ҵ���һ�������ĵ�С��Ԫ��
		while (low < high && *(L + high) >= key)
			high--;
		// ����Ԫ�طŵ����ĵ����
		*(L + low) = *(L + high);

		// ���������ҵ���һ�������ĵ���Ԫ��
		while (low < high && *(L + low) <= key)
			low++;
		// ����Ԫ�طŵ����ĵ��ұ�
		*(L + high) = *(L + low);
	}
	// �����ĵ�ŵ�����λ��
	*(L + high) = key;
	// �������ĵ��λ��
	return low;
}

// ��������ĵݹ麯��
void QuickSort(int*& L, int low, int high)
{
	if (low < high)
	{
		// �����з�Ϊ������
		int pivotloc = Quick_Sort(L, low, high);
		// ����벿�ֽ�������
		QuickSort(L, low, pivotloc - 1);
		// ���Ұ벿�ֽ�������
		QuickSort(L, pivotloc + 1, high);
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
	QuickSort(L, 0, 7);
	ouput(L);
}