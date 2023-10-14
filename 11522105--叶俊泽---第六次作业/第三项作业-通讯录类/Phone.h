#include<iostream>
#include<iomanip>
#include<cstring>
#include<cstdio>
using namespace std;
void SafeStrCopy(char* dest, const char* src, int destSize) 
{
	int i = 0;
	while (src[i] != '\0') 
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0'; // 手动添加终止符
}

void PrintStringUntilNullTerminator(char* str) 
{
	for (int i = 0; str[i] != '\0'; i++) {
		cout << str[i];
	}
	cout << endl;
}
class PhoneBook 
{

private:
	char Name[100];
	char PhoneNum[100];
	char* address;
public:
		PhoneBook()
		{
			Name[0] = '\0';
			PhoneNum[0] = '\0';
			address = NULL;
		}
		PhoneBook(char* a, char* b, char* c) 
		{
			SafeStrCopy(Name, a,strlen(a));
			SafeStrCopy(PhoneNum, b,strlen(b));
			address = new char[100];
			SafeStrCopy(address, c,strlen(c));
		}
		~PhoneBook()
		{
			//delete address;
		}
		PhoneBook(const PhoneBook& other) 
		{
			SafeStrCopy(Name, other.Name, strlen(other.Name));
			SafeStrCopy(PhoneNum, other.PhoneNum, strlen(other.PhoneNum));
			address = new char[100];
			SafeStrCopy(address, other.address, strlen(other.address));
		}
		void Display() 
		{
			cout << "姓名: "<< endl;
			PrintStringUntilNullTerminator(Name);
			cout << "电话号码: "<< endl;
			PrintStringUntilNullTerminator(PhoneNum);
			cout << "地址: " << endl;
			PrintStringUntilNullTerminator(address);
		}
};

