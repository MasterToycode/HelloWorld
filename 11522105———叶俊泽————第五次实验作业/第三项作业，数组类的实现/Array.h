#include<iostream>
#include<algorithm>
using namespace std;
const int Maxsize = 10;
bool descendingOrder(int a, int b)
{
	return a > b;
}
class Array 
{
private :
	int length;
	int* M;
public:
	Array(int x): length(x)
	{
		M = NULL;
		length = x;
	}
	~Array()
	{
		delete[]M;
	}

	void IuPut();
	void Display();
	void Sort(char x);
	int Search(int element);
	void Insert(int number);
	void Delete(int element);
};

void Array::IuPut() 
{
	M = new int[length];
	for (int i = 0; i < length; i++) 
	{
		cin >> M[i];
	}
}

void Array::Display() 
{
	for (int i = 0; i < length; ++i) {
		cout << M[i] << " ";
	}

	cout << endl;
}

void Array::Sort(char x) {
	if (x == 'a') {
		sort(M, M + length);
	}
	if (x == 'd') {
		sort(M, M + length, descendingOrder);
	}
}


int Array::Search(int element) 
{
	int left = 0;
	int right = length - 1;

	while (left <= right) {
		int mid = left + (right - left) / 2;

		if (M[mid] == element) {
			return mid; // 找到了
		}
		else if (M[mid] < element) {
			left = mid + 1; // 在右半部分继续搜索
		}
		else {
			right = mid - 1; // 在左半部分继续搜索
		}
	}
	return -1; // 没找到
}



void Array::Insert(int number)
{
	// 检查数组是否已满
	if (length == Maxsize)
	{
		std::cout << "插入失败，数组已满" << std::endl;
		return; // 中止函数的执行
	}
	int left = 0;
	int right = length - 1;
	int mid;
	// 使用二分查找找到插入位置
	while (left <= right)
	{
		mid = left + (right - left) / 2; // 使用除法计算mid
		if (number < M[mid])
		{
			right = mid - 1;
		}
		else if (number > M[mid])
		{
			left = mid + 1;
		}
		else
		{
			// 如果元素已经存在，根据需求决定是插入到左侧还是右侧
			// 这里插入到右侧
			left = mid + 1;
		}
	}
	// 使用std::copy复制元素，将元素右移
	std::copy(M + left, M + length, M + left + 1);
	// 插入元素到正确位置
	M[left] = number;
	length++;
}


void Array::Delete(int element) 
{
	int index = Array::Search(element); // 查找元素位置
	if (length == 0) {
		cout << "删除失败！" << endl;
	}
	else if (index == -1) {
		cout << "删除的元素不存在！" << endl;
	}
	else {
		copy(M + index + 1, M + length, M + index);
		length--;
	}
}

