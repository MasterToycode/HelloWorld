#include"h1.h"
void Explation()
{
    cout << "  ------------------------------------------"
        << "欢迎使用数据结构排序算法分析设计---------------------------------------- " << endl
        << "该算法分析分为两个大的类别，供您选择！" << endl
        << "1.对随机生成的3组500个待排整数进行排序" << endl
        << "2.随机产生3组数据——1000、10000、100000个待排整数，存入文件，从文件读入待排数据进行排序" << endl
        << "每一次启动程序之前您都有一次机会选择您想要的类别，但是您可以有多次机会选择排序的算法！"<<endl
        << "您只需要按照程序的提示正确输入信息即可对不同的排序算法进行分析！" << endl
        << "不足指出还望您批评指正！" << endl << endl;
}



void printHorizontalLine()
{
    string horizontalLine(50, '-');
    cout << horizontalLine << endl << endl;
}


// 生成随机数并存储在传入的 vector 中
void GenerateRandomNumbers(vector<int>& numbers, int size,int t)
{
    // 设置随机数引擎和种子
    default_random_engine generator(static_cast<unsigned>(time(nullptr) + t));
    uniform_int_distribution<int> distribution(1, 100000); // 1到100000的随机数分布

    for (int i = 0; i < size; ++i)
    {
        numbers.push_back(distribution(generator)); // 生成随机数
    }
}



void OutPut(long long int& moves, long long int& comparisons, double& SortingTime)
{
    cout << "排序完成！" << endl;
    cout << "比较次数：" << comparisons << " 次" << endl;
    cout << "移动次数：" << moves << " 次" << endl;
    cout << "排序时间：" << SortingTime << " 秒" << endl << endl;
}



//生成随机数并写入文件！
void generateRandomNumbersToFile(string& filename,int count,int t)
{
    ofstream file(filename);
    if (!file)
    {
        cout<< "无法打开文件" <<endl;
        return;
    }

    // 设置随机数引擎和种子
    default_random_engine generator(static_cast<unsigned>(time(nullptr) + t));
    uniform_int_distribution<int> distribution(1, 100000); // 1到100000的随机数分布

    for (int i = 0; i <count; ++i)
    {
        int random_num = distribution(generator); // 生成随机数
        file << random_num << endl;                 // 写入文件
    }

    file.close();
    cout << "输入数据成功！" << endl;
}


/*
 string filePath1 = "D:\\不会编程\\数据结构\\Data Strcuture Design\\ConsoleApplication1\\课设排序数据\\1000.txt";
    int count1 = 1000; // 你想生成的随机数数量

    string filePath2 = "D:\\不会编程\\数据结构\\Data Strcuture Design\\ConsoleApplication1\\课设排序数据\\10000.txt";
    int count2 = 10000; // 你想生成的随机数数量

    string filePath3 = "D:\\不会编程\\数据结构\\Data Strcuture Design\\ConsoleApplication1\\课设排序数据\\100000.txt";
    int count3 = 100000; // 你想生成的随机数数量
*/







// 从文件中读取数据并存储到向量中
void readDataFromFile(string& filename, vector<int>& data) 
{
    ifstream file(filename);
    if (!file) 
    {
        cout << "无法打开文件" << endl;
        return;
    }

    int number;
    while (file >> number) 
    {
        data.push_back(number);
    }

    cout << "数据读出成功！" << endl;
    file.close();
}

