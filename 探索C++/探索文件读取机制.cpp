#include <iostream>   
#include <fstream>    
#include <string>
using namespace std;
int  main()
{
    /*
    ofstream myf("D:\\������\\��ʱ��.txt");//Ĭ��ios::out��ios::trunc
    char txt[255];
    while (1)
    {
        cin.getline(txt, 255);
        if (strlen(txt) == 0)
            break;
        myf << txt << endl;
    }
    */
    ifstream myf1("D:\\������\\��ʱ��.txt", ios::_Nocreate);

    if (myf1.fail())
    {
        cout << "No exist! " << endl;
        return 0;
    }

    char txt1[255];
    myf1 >> txt1;
    int counnt = 0;//���ѭ�����ж�ȡ�����ݵĴ�����
    while (!myf1.eof())
        /*
         eof() �����ڶ�ȡ���ļ�ĩβ֮ǰһֱ���� false��ֻ���ڳ��Զ�ȡ�ļ�ĩβʱ�Ż��Ϊ true��
        */


    {
        cout << txt1 << endl;
        myf1 >> txt1;
        /*
        myf1 >> txt1; ���������Ǵ��ļ������� myf1 �ж�ȡһ�����ʣ��Կո��Ʊ�����з�Ϊ�ָ�������
        ������洢���ַ����� txt1 �С�
        �Ⲣ���ǽ��ļ�����������һ���Զ��� txt1 �����С�
        */
        ++counnt;
    }
    cout << "Times: " << counnt << endl;
    myf1.close();//�ر��ļ������ù��캯�����ļ������ùر��ļ���
}
