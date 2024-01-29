#include <iostream>   
#include <fstream>    
#include <string>
using namespace std;
int  main()
{
    /*
    ofstream myf("D:\\不会编程\\临时的.txt");//默认ios::out和ios::trunc
    char txt[255];
    while (1)
    {
        cin.getline(txt, 255);
        if (strlen(txt) == 0)
            break;
        myf << txt << endl;
    }
    */
    ifstream myf1("D:\\不会编程\\临时的.txt", ios::_Nocreate);

    if (myf1.fail())
    {
        cout << "No exist! " << endl;
        return 0;
    }

    char txt1[255];
    myf1 >> txt1;
    int counnt = 0;//存放循环体中读取新内容的次数！
    while (!myf1.eof())
        /*
         eof() 函数在读取到文件末尾之前一直返回 false，只有在尝试读取文件末尾时才会变为 true。
        */


    {
        cout << txt1 << endl;
        myf1 >> txt1;
        /*
        myf1 >> txt1; 语句的作用是从文件输入流 myf1 中读取一个单词（以空格、制表符或换行符为分隔符），
        并将其存储到字符数组 txt1 中。
        这并不是将文件的所有内容一次性读入 txt1 变量中。
        */
        ++counnt;
    }
    cout << "Times: " << counnt << endl;
    myf1.close();//关闭文件（若用构造函数打开文件，则不用关闭文件）
}
