#include <iostream>
#include <stdexcept>
using namespace std;

void innerFunction()
{
    try
    {
        // �������׳�һ���쳣
        throw runtime_error("Inner function exception");
    }

    catch (const exception& e)
    {
        cerr << "At the Function of the innerFunction ! Caught exception inside innerFunction: " << e.what() << endl;
        throw;
        //throw��ָ���κβ��������������׳���ǰ���ڴ�����쳣������ָ�������try������е��쳣
        //����쳣���ݵ���outer Function������catch
        //������Ȩ�����������еĸ��߼���� catch ���顣
    }
}



void outerFunction()
{
    try
    {
        // �����ڲ�����
        innerFunction();
    }

    catch (const exception& e)
    {
        cerr << "At teh Function of the outerFunction !Caught exception inside outerFunction: " << e.what() << endl;
        // ��������н�һ������
        //ָ�����innerFunction�������������쳣��
        throw;
    }
}




int main()
{
    try
    {
        // �����ⲿ����
        outerFunction();
    }

    catch (const exception& e)
    {
        cerr << "At the function of the main ! Caught exception inside main: " << e.what() << endl;
        // ������쳣������outerFunction�������ݶ������쳣�������outerFunction������û�������׳��쳣
        //�����main�����Ͳ���ִ��������䣬��Ϊ�쳣�Ѿ���outerFunction�����д����ˣ�
    }
    return 0;
}



/*
*
����������£�
main ���������� outerFunction��
outerFunction �ڲ������� innerFunction��
innerFunction �׳��쳣�������� catch ���顣
�� catch ������ʹ�� throw; �����׳��쳣��
��������׳����쳣��������ݵ����� innerFunction �ĵط����� outerFunction��
outerFunction �е���Ӧ catch ����Ҳ����������쳣��
���ԣ��쳣�Ĵ������ڵ������еĲ�ͬ����֮����еġ�


�� innerFunction �������׳��쳣������������ innerFunction �ڼ�������
���Ƿ��ص����� innerFunction ����һ������ outerFunction �У�
�Ӷ��� outerFunction �� catch �����н��д���

*/