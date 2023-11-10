#include<iostream>
#include<string>
using namespace std;
class CStr1 
{
protected: 
	string Str1;
public:
	CStr1(string a):Str1(a){}

	void ShowStr1() 
	{
		cout << Str1 << endl;
	}

	void ChangeStr1(string b) 
	{
		Str1 = b;
	}

};

class CStr2 :public CStr1
{
protected: string Str2;
public:
	CStr2(string a,string b):CStr1(a),Str2(b){}

	void ShowStr() 
	{
		cout << Str1 << endl
			<< Str2 << endl;
	}

	void ChangeStr() 
	{
		Str2 = Str1 + Str2;
		cout << Str2 << endl;
	}
};