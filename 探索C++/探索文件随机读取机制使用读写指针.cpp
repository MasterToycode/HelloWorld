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


    // 以读写模式打开文件
    fstream file("example.txt", ios::in | ios::out);



    if (!file.is_open())
    {
        cerr << "Error opening the file." << endl;
        return 1;
    }



    // 使用seekp()设置写指针位置，将"NEW LINE"插入到第二行之后
    file.seekp(15, ios::beg);  // 移到第一行末尾的位置
    file << "NEW LINE" << endl;



    // 使用seekg()设置读指针位置，读取文件的内容并输出
    file.seekg(0, ios::beg);  // 移到文件开头
    string line;



    while (getline(file, line))
    {
        cout << line << endl;
    }
    file.close();


    return 0;
}
