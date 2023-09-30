#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
void Getchar(std::string& s) 
{
	char x='\0';
	while (x != '\n') {
		x = getchar();
		if (x != '\n')s += x;// 将字符附加到字符串
	}
}

class Singer 
{
private:
	string  name, gender, song;
	int age;
public:
	void Enroll();
	void Display();
	void Modify();
};

void Singer::Enroll() 
{
	cout << "请依次输入名字（name）、性别（gender）、年龄（age）、演唱曲目（song）：" << endl;
	Getchar(name);
	Getchar(gender);
	cin >> age;
	getchar();
	Getchar(song); 
	cout << endl;
}

void Singer::Display() 
{
	cout << Singer::name<<endl
		<< Singer::gender<<endl
		<< Singer::age<<endl
		<< Singer::song<< endl;
}

void Singer::Modify() 
{
	cout << "1、名字（name） 2、性别（gender） 3、年龄（age） 4、演唱曲目（song）" << endl
		<< "请输入需要修改的选项：";
	int choose;
	cin >> choose;
	getchar();
	switch (choose)
	{
	case 1:
	{
		cout << "请输入需要新的名字：";
		string g;
		Getchar(g);
		name = g;
			cout<< "歌手信息修改成功"
			<< endl;
		break;
	}
	case 2:
	{
		cout << "请输入需要新的性别：";
		string g;
		Getchar(g);
		gender = g;
		cout << "歌手信息修改成功"
			<< endl;
		break;
	}
	case 3:
	{
		cout << "请输入需要新的年龄：";
		cin >> Singer::age;
		cout << "歌手信息修改成功"
			<< endl;
		break;
	}
	case 4:
	{
		cout << "请输入需要新的演唱曲目：";
		string g;
		Getchar(g);
		song = g;
		cout << "歌手信息修改成功"
			<< endl;
		break;
	}
	default:
		cout << "歌手信息修改失败！"
			<< endl;
		break;
	}

}