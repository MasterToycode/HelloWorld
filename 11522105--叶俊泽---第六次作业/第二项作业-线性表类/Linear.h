#include<iostream>
#include<iomanip>
using namespace std;
class Linear 
{
private: 
	int Max;
	int Num;
	int* linear;
public:
	~Linear() 
	{
		delete linear;
	}
	Linear(int n=10) 
	{
		
		linear = new int[n];
		Max = n;
		Num = 0;
	}
	void Add(int elemnet);
	void Output();
};

void Linear::Add(int elemnet) 
{
	if (Num < Max)linear[Num++] = elemnet;
	else 
	{
		int* newlinear = new int[Max + 5];
		for (int i = 0; i < Max; i++)newlinear[i] = linear[i];
		delete linear;
		Max = Max + 5;
		linear = newlinear;
		linear[Num++] = elemnet;
	}
}


void Linear::Output()
{
	for (int i = 0; i < Num; i++) 
	{
		cout << setw(3) << int(linear[i]) << right;
	}

}