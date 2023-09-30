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
			return mid; // �ҵ���
		}
		else if (M[mid] < element) {
			left = mid + 1; // ���Ұ벿�ּ�������
		}
		else {
			right = mid - 1; // ����벿�ּ�������
		}
	}
	return -1; // û�ҵ�
}



void Array::Insert(int number)
{
	// ��������Ƿ�����
	if (length == Maxsize)
	{
		std::cout << "����ʧ�ܣ���������" << std::endl;
		return; // ��ֹ������ִ��
	}
	int left = 0;
	int right = length - 1;
	int mid;
	// ʹ�ö��ֲ����ҵ�����λ��
	while (left <= right)
	{
		mid = left + (right - left) / 2; // ʹ�ó�������mid
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
			// ���Ԫ���Ѿ����ڣ�������������ǲ��뵽��໹���Ҳ�
			// ������뵽�Ҳ�
			left = mid + 1;
		}
	}
	// ʹ��std::copy����Ԫ�أ���Ԫ������
	std::copy(M + left, M + length, M + left + 1);
	// ����Ԫ�ص���ȷλ��
	M[left] = number;
	length++;
}


void Array::Delete(int element) 
{
	int index = Array::Search(element); // ����Ԫ��λ��
	if (length == 0) {
		cout << "ɾ��ʧ�ܣ�" << endl;
	}
	else if (index == -1) {
		cout << "ɾ����Ԫ�ز����ڣ�" << endl;
	}
	else {
		copy(M + index + 1, M + length, M + index);
		length--;
	}
}

