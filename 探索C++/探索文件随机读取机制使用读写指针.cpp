#include <iostream>
#include <fstream>
#include<string>
using namespace std;

int main()
{

    ofstream outFile("example.txt");
    outFile << "This is line 1.\n";
    outFile << "This is line 2.\n";
    outFile << "This is line 3.\n";
    outFile.close();


    // �Զ�дģʽ���ļ�
    fstream file("example.txt", ios::in | ios::out);



    if (!file.is_open())
    {
        cerr << "Error opening the file." << endl;
        return 1;
    }



    // ʹ��seekp()����дָ��λ�ã���"NEW LINE"���뵽�ڶ���֮��
    file.seekp(15, ios::beg);  // �Ƶ���һ��ĩβ��λ��
    file << "NEW LINE" << endl;



    // ʹ��seekg()���ö�ָ��λ�ã���ȡ�ļ������ݲ����
    file.seekg(0, ios::beg);  // �Ƶ��ļ���ͷ
    string line;



    while (getline(file, line))
    {
        cout << line << endl;
    }
    file.close();


    return 0;
}
