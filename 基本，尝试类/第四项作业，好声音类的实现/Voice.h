#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
void Getchar(std::string& s) 
{
	char x='\0';
	while (x != '\n') {
		x = getchar();
		if (x != '\n')s += x;// ���ַ����ӵ��ַ���
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
	cout << "�������������֣�name�����Ա�gender�������䣨age�����ݳ���Ŀ��song����" << endl;
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
	cout << "1�����֣�name�� 2���Ա�gender�� 3�����䣨age�� 4���ݳ���Ŀ��song��" << endl
		<< "��������Ҫ�޸ĵ�ѡ�";
	int choose;
	cin >> choose;
	getchar();
	switch (choose)
	{
	case 1:
	{
		cout << "��������Ҫ�µ����֣�";
		string g;
		Getchar(g);
		name = g;
			cout<< "������Ϣ�޸ĳɹ�"
			<< endl;
		break;
	}
	case 2:
	{
		cout << "��������Ҫ�µ��Ա�";
		string g;
		Getchar(g);
		gender = g;
		cout << "������Ϣ�޸ĳɹ�"
			<< endl;
		break;
	}
	case 3:
	{
		cout << "��������Ҫ�µ����䣺";
		cin >> Singer::age;
		cout << "������Ϣ�޸ĳɹ�"
			<< endl;
		break;
	}
	case 4:
	{
		cout << "��������Ҫ�µ��ݳ���Ŀ��";
		string g;
		Getchar(g);
		song = g;
		cout << "������Ϣ�޸ĳɹ�"
			<< endl;
		break;
	}
	default:
		cout << "������Ϣ�޸�ʧ�ܣ�"
			<< endl;
		break;
	}

}