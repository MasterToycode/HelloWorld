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



// 插入排序算法
void Insertsort(int*& L)
{
	// 从第二个元素开始遍历
	for (int i = 1; i < 8; i++)
	{
		// 取出当前遍历到的元素
		int end = *(L + i);
		// 从当前元素的前一个元素开始遍历
		int key = i - 1;
		// 如果当前元素小于前一个元素，则将前一个元素后移一位
		while (key >= 0 && *(L + key) > end)
		{
			*(L + key + 1) = *(L + key);
			key--;
		}
		// 将当前元素插入到合适的位置
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