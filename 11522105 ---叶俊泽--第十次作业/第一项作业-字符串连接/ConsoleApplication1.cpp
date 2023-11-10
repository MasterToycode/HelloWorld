#include"Stringcat.h"
int main() 
{
	cout << "请输入两个字符串:";
	string a, b;
	cin >> a >> b;
	CStr2 STR(a, b);
	STR.ShowStr();
	STR.ChangeStr();
}