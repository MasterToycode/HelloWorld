#include <iostream>
#include <iomanip> 
#include<string>
using namespace std;
int main()
{
    /*
    // ���� skipws ��־����������ȡ����ʱ�����հ��ַ�
    cout << "������һ�������������հ��ַ�����";
    cin >> skipws;  // ���� skipws ��־
    string number1;
    cin >> number1;
    cout << "������������ǣ�" << number1 << endl;
    cout << setw(10) << setfill('*') << right << "Right Aligned" << endl;
    cout << setw(10) << setfill('*') << left << "Left Aligned" << endl;


    // ʹ�ö����־ internal����������룬�����Ҷ������
    int negativeNumber = -12345;
    cout << setw(15) << setfill(' ') << internal << negativeNumber << endl;


    int number = 255;
    cout << "Ĭ�������ʮ���ƣ�: " << number << endl;
    cout << "�˽������: " << oct << showbase << showpos << showpoint << number << endl;
    cout << "ʮ���������: " <<hex<<uppercase<< number << endl;
    cout << "�ָ�ʮ�������: " << dec<< number << endl<<endl;
    */



    double number2 = 123456.789;
    cout << "Ĭ�����: " << number2 << endl;
    cout << "��ѧ���������: " << scientific << number2 << endl;
    cout << "�����ʾ�����: " << fixed << number2 << endl;
    cout.unsetf(ios::scientific | ios::fixed);
    cout << "�ָ�Ĭ�����: " << number2 << endl << endl;





    cout << "�������ı���ÿ����һ�����Ž������룺" << std::endl;
    string inputText;
    // ʹ�� std::getline ��ȡһ���ı���ֱ����������Ϊֹ
    getline(cin, inputText, ',');
    cout << "��ȡ�����ı��ǣ�" << inputText << std::endl;


    return 0;
}
