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




// 快速排序的核心算法，将序列分为两部分，左边比中心点小，右边比中心点大
int Quick_Sort(int*& L, int low, int high)
{
	// 以第一个元素为中心点
	int key = *(L + low);
	while (low < high)
	{
		// 从右往左找到第一个比中心点小的元素
		while (low < high && *(L + high) >= key)
			high--;
		// 将该元素放到中心点左边
		*(L + low) = *(L + high);

		// 从左往右找到第一个比中心点大的元素
		while (low < high && *(L + low) <= key)
			low++;
		// 将该元素放到中心点右边
		*(L + high) = *(L + low);
	}
	// 将中心点放到最终位置
	*(L + high) = key;
	// 返回中心点的位置
	return low;
}

// 快速排序的递归函数
void QuickSort(int*& L, int low, int high)
{
	if (low < high)
	{
		// 将序列分为两部分
		int pivotloc = Quick_Sort(L, low, high);
		// 对左半部分进行排序
		QuickSort(L, low, pivotloc - 1);
		// 对右半部分进行排序
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