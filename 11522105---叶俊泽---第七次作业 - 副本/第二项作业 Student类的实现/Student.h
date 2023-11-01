#include<iostream>
#include<string>
#include<sstream>
using namespace std;
void PrintStringUntilNullTerminator(char* str)
{
	for (int i = 0; str[i] != '\0'; i++) 
	{
		cout << str[i];
	}
	cout << endl;
}
void PrintStringUntilNullTerminator(int* str)
{
	for (int i = 0; str[i] != '\0'; i++) 
	{
		cout << str[i];
	}
	cout << endl;
}


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
void SafeStrCopy(int* dest,  int* src)
{
	int i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0'; // 手动添加终止符
}



class Student 
{
	private:
		long int sno;
		char sname[50];
		char gender[20];
		char grade[50];
	public:
		Student(int a, char* b, char* c,char *d)
		{
			sno = a;
			SafeStrCopy(sname, b, strlen(b));
			SafeStrCopy(gender, c, strlen(c));
			SafeStrCopy(grade, d, strlen(d));
		}
		void Student_show() 
		{
			cout << "This student's information is displayed as follow:" << endl;
			cout << sno<<endl;
			PrintStringUntilNullTerminator(sname);
			PrintStringUntilNullTerminator(gender);
			PrintStringUntilNullTerminator(grade);
		}
};

class Scource 
{
private:
	char cno[50];
	char scource[50];
public:
	Scource(char* a, char* b)
	{
		SafeStrCopy(cno, a, strlen(a));
		SafeStrCopy(scource, b, strlen(b));
	}
	void Scource_show() 
	{
		PrintStringUntilNullTerminator(cno);
		PrintStringUntilNullTerminator(scource);
	}
};

class Sscore 
{
private:
	float score;
public:
	Sscore(int x):score(x)
	{
	
	}
	void Sscore_show() 
	{
		cout << score << endl;
	}
};