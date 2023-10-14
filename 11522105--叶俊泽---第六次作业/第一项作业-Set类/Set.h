#include<iostream>
#include<iomanip>
using namespace std;
const int number = 10;
class Set
{
private:
	int a[number];
public:
	Set(int *b)
	{
		for (int i = 0; i < number; i++) 
		{
			a[i] = b[i];
		}
	}
	void Output();
	int Find(int element);
};

void Set::Output() 
{
	for (int i = 0; i < number; i++) 
	{
		cout << setw(3) << a[i] << right;
		if((i+1)%5==0)cout<<endl;
	}
}
 

int Set::Find(int element) 
{
	int left = 0;
	int right = number - 1;

	while (left <= right) {
		int mid = left + (right - left) / 2;

		if (a[mid] == element) {
			return mid; // 找到了
		}
		else if (a[mid] < element) {
			left = mid + 1; // 在右半部分继续搜索
		}
		else {
			right = mid - 1; // 在左半部分继续搜索
		}
	}
	return -1; // 没找到
}