#include<iostream>
using namespace std;
// ��������һ������
int& getReference() 
{
	static int x = 5;  // ʹ�� static �Ա��ⷵ�ؾֲ������ĵ�ַ
	//��ע�⣬ʹ�����÷���ֵҪС�ģ�ȷ��������ָ��ֲ����������ã�
	return x;
}

int main()
{
	int num = 50;
	int& re = num;
	int& re1 = re;
	int* p = &num;
	cout << re << endl
		<< *p << endl
		<< num << endl;

	re1 = 100;
	cout << re << endl
		<< *p << endl
		<< num << endl << endl;

	cout << "������̽���������ú�ָ��" << endl << endl;



	// ����������Ϊ��ֵ
	getReference() = 10;

	// ��ȡ���ò����
	int& ref = getReference();
	cout << "Value of ref: " << ref << endl;

	cout << "������̽��������Ϊ��������ֵ" << endl << endl;




	int i = 10;
	int j = 20;

	// �������ò���ʼ��
	int& ref1 = i;

	cout << "Initial value of i: " << i << endl;
	cout << "Value through ref: " << ref1 << endl;

	// �޸�ԭʼ���� i������Ҳ�ᷴӳ����仯
	i = 30;
	cout << "Modified value of i: " << i << endl;
	cout << "Value through ref: " << ref1 << endl;

	// ref = &j;  // �������ò������¹�������һ������
	// ref = j;   // ��ȷ���޸���ԭʼ���� i ��ֵ�����������ù����Ķ���

	cout << "������̽������һ������ʼ���Ͳ����ٴα����ù����µĶ���" << endl;
}

