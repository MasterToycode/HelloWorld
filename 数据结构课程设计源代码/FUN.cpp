#include"h1.h"
void Explation()
{
    cout << "  ------------------------------------------"
        << "��ӭʹ�����ݽṹ�����㷨�������---------------------------------------- " << endl
        << "���㷨������Ϊ���������𣬹���ѡ��" << endl
        << "1.��������ɵ�3��500������������������" << endl
        << "2.�������3�����ݡ���1000��10000��100000�����������������ļ������ļ�����������ݽ�������" << endl
        << "ÿһ����������֮ǰ������һ�λ���ѡ������Ҫ����𣬵����������ж�λ���ѡ��������㷨��"<<endl
        << "��ֻ��Ҫ���ճ������ʾ��ȷ������Ϣ���ɶԲ�ͬ�������㷨���з�����" << endl
        << "����ָ������������ָ����" << endl << endl;
}



void printHorizontalLine()
{
    string horizontalLine(50, '-');
    cout << horizontalLine << endl << endl;
}


// ������������洢�ڴ���� vector ��
void GenerateRandomNumbers(vector<int>& numbers, int size,int t)
{
    // ������������������
    default_random_engine generator(static_cast<unsigned>(time(nullptr) + t));
    uniform_int_distribution<int> distribution(1, 100000); // 1��100000��������ֲ�

    for (int i = 0; i < size; ++i)
    {
        numbers.push_back(distribution(generator)); // ���������
    }
}



void OutPut(long long int& moves, long long int& comparisons, double& SortingTime)
{
    cout << "������ɣ�" << endl;
    cout << "�Ƚϴ�����" << comparisons << " ��" << endl;
    cout << "�ƶ�������" << moves << " ��" << endl;
    cout << "����ʱ�䣺" << SortingTime << " ��" << endl << endl;
}



//�����������д���ļ���
void generateRandomNumbersToFile(string& filename,int count,int t)
{
    ofstream file(filename);
    if (!file)
    {
        cout<< "�޷����ļ�" <<endl;
        return;
    }

    // ������������������
    default_random_engine generator(static_cast<unsigned>(time(nullptr) + t));
    uniform_int_distribution<int> distribution(1, 100000); // 1��100000��������ֲ�

    for (int i = 0; i <count; ++i)
    {
        int random_num = distribution(generator); // ���������
        file << random_num << endl;                 // д���ļ�
    }

    file.close();
    cout << "�������ݳɹ���" << endl;
}


/*
 string filePath1 = "D:\\������\\���ݽṹ\\Data Strcuture Design\\ConsoleApplication1\\������������\\1000.txt";
    int count1 = 1000; // �������ɵ����������

    string filePath2 = "D:\\������\\���ݽṹ\\Data Strcuture Design\\ConsoleApplication1\\������������\\10000.txt";
    int count2 = 10000; // �������ɵ����������

    string filePath3 = "D:\\������\\���ݽṹ\\Data Strcuture Design\\ConsoleApplication1\\������������\\100000.txt";
    int count3 = 100000; // �������ɵ����������
*/







// ���ļ��ж�ȡ���ݲ��洢��������
void readDataFromFile(string& filename, vector<int>& data) 
{
    ifstream file(filename);
    if (!file) 
    {
        cout << "�޷����ļ�" << endl;
        return;
    }

    int number;
    while (file >> number) 
    {
        data.push_back(number);
    }

    cout << "���ݶ����ɹ���" << endl;
    file.close();
}

