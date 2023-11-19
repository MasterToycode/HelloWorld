#include"h1.h"
int main() 
{   
    //数据文件的路径！
     string filePath1 = "D:\\不会编程\\数据结构\\Data Strcuture Design\\ConsoleApplication1\\课设排序数据\\1000.txt";
     string filePath2 = "D:\\不会编程\\数据结构\\Data Strcuture Design\\ConsoleApplication1\\课设排序数据\\10000.txt";
     string filePath3 = "D:\\不会编程\\数据结构\\Data Strcuture Design\\ConsoleApplication1\\课设排序数据\\100000.txt";

     //说明程序操作！
    Explation();
    vector<long long int> moves(3, 0); // 创建一个大小为3的数组来存储移动次数
    vector<long long int> comparisons(3, 0); // 创建一个大小为3的数组来存储比较次数

    //记录执行时间！
    double SortingTime1 = 0.0;
    double SortingTime2 = 0.0;
    double SortingTime3 = 0.0;

    // 创建三组数组用于存储数据！
    vector<int> data1;
    vector<int> data2;
    vector<int> data3;


    // 定义一个布尔类型变量，表示用户选择数据来源是否有效
    bool validdatachioce = false;

    while (!validdatachioce) // 当用户选择数据来源无效时，执行以下循环
    {
        // 提示用户选择数据来源
        cout << "请选择数据来源：" << endl;
        cout << "1. 随机生成数据" << endl;
        cout << "2. 从文件读取数据" << endl;
        cout << "请输入您的选择：(1 or 2)";

        int dataChoice; // 定义一个整型变量，表示用户选择的数据来源
        string input1; // 定义一个字符串变量，用于读取用户输入
        cin >> input1; // 读取用户输入
        bool Isitnumber = true; // 定义一个布尔类型变量，表示用户输入是否都是数字

        // 检查输入是否都是数字
        for (char c : input1)
        {
            if (!isdigit(c))
            {
                Isitnumber = false;
                break;
            }
        }

        // 如果用户输入都是数字
        if (Isitnumber)
        {
            dataChoice = stoi(input1); // 将用户输入转换成整型
            switch (dataChoice)
            {
            case 1:
                // 生成随机数据
                GenerateRandomNumbers(data1, 5000, 1);
                GenerateRandomNumbers(data2, 5000, 2);
                GenerateRandomNumbers(data3, 5000, 3);
                validdatachioce = true; // 数据来源选择有效，跳出循环
                break;
            case 2:

                // 从文件读取数据
                if (readDataFromFile(filePath1, data1)==1&& readDataFromFile(filePath2, data2)==1&& readDataFromFile(filePath3, data3)==1)
                {
                    validdatachioce = true; // 数据来源选择有效，跳出循环
                    break;
                }//数据文件路径正确并且成功读取！

                else 
                {
                    GenerateRandomNumbers(data1, 5000, 1);
                    GenerateRandomNumbers(data2, 5000, 2);
                    GenerateRandomNumbers(data3, 5000, 3);
                    validdatachioce = true; // 数据来源选择有效，跳出循环
                    cout << "文件路径不正确，自动选择随机数生成的数据！" << endl;
                    break;
                }

            default:
                // 用户选择无效，提示重新输入
                cout << "选择无效的数据来源，请重新输入。" << endl << endl;
                break;
            }
        }

        else // 如果用户输入不是数字
        {
            cout << "请输入有效的数字选项。" << endl << endl; // 提示用户重新输入
            cin.clear();  // 清除错误状态
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 清空输入缓冲区
        }
    }


    cout <<endl<< "数据选择成功！" << endl;
    this_thread::sleep_for(chrono::seconds(1));
    system("cls"); // 对于Windows系统
    printHorizontalLine();
    

    char continueSorting = 'y';
   
    //进入主循环
    while (continueSorting == 'y') 
    {
        int choice;
        bool validChoice = false;

        //进入次循环，直至正确输入开始排序！
        while (!validChoice) 
        {    
            
            // 在每次选择排序算法后，清零 moves 和 comparisons 数组
            for (int i = 0; i < 3; ++i)
            {
                moves[i] = 0;
                comparisons[i] = 0;
            }

            //在每次选择排序算法后，清零时间
            SortingTime1 = 0.0;
            SortingTime2 = 0.0;
            SortingTime3 = 0.0;


            cout << "请选择排序算法：" << endl;
            cout << "1. 希尔排序" << endl;
            cout << "2. 堆排序" << endl;
            cout << "3. 快速排序" << endl;
            cout << "4. 基数排序" << endl;
            cout << "5. 折半插入排序" << endl;


            //以下的设计思想和判断数据选择的时候是一样的！
            
            // 读取用户输入
            string input;
            cout << "请输入您要选择的排序算法：( 1 or 2 or 3 or 4 or 5)";
            cin >> input;
            printHorizontalLine();

            // 检查输入是否都是数字
            bool isAllDigits = true;

            for (char c : input) 
            {
                if (!isdigit(c)) 
                {
                    isAllDigits = false;
                    break;
                }
            }


            //如果输入的是数字！
            if (isAllDigits)
            {
                choice = stoi(input);  // 将字符串转换为整数

                //进入核心程序----选择排序算法排序！

                switch (choice) //根据用户选择的排序算法，选择相应的函数进行排序
                {
                case 1:
                    SortingTime1 = measureSortingTime1(data1, moves[0], comparisons[0]); //调用希尔排序函数，返回排序时间，并记录数据移动次数和比较次数
                    SortingTime2 = measureSortingTime1(data2, moves[1], comparisons[1]);
                    SortingTime3 = measureSortingTime1(data3, moves[2], comparisons[2]);
                    cout << "希尔排序结果：" << endl << endl; //输出排序结果
                    validChoice = true;
                    break;
                case 2:
                    SortingTime1 = measureSortingTime2(data1, data1.size(), moves[0], comparisons[0]); //调用堆排序函数，返回排序时间，并记录数据移动次数和比较次数
                    SortingTime2 = measureSortingTime2(data2, data2.size(), moves[1], comparisons[1]);
                    SortingTime3 = measureSortingTime2(data3, data3.size(), moves[2], comparisons[2]);
                    cout << "堆排序结果：" << endl << endl; //输出排序结果
                    validChoice = true;
                    break;
                case 3:
                    SortingTime1 = measureSortingTime3(data1, 0, data1.size() - 1, moves[0], comparisons[0]); //调用快速排序函数，返回排序时间，并记录数据移动次数和比较次数
                    SortingTime2 = measureSortingTime3(data2, 0, data2.size() - 1, moves[1], comparisons[1]);
                    SortingTime3 = measureSortingTime3(data3, 0, data3.size() - 1, moves[2], comparisons[2]);
                    cout << "快速排序结果：" << endl << endl; //输出排序结果
                    validChoice = true;
                    break;
                case 4:
                    SortingTime1 = measureSortingTime4(data1, moves[0], comparisons[0]); //调用基数排序函数，返回排序时间，并记录数据移动次数和比较次数
                    SortingTime2 = measureSortingTime4(data1, moves[1], comparisons[1]);
                    SortingTime3 = measureSortingTime4(data3, moves[2], comparisons[2]);
                    cout << "基数排序结果：" << endl << endl; //输出排序结果
                    validChoice = true;
                    break;
                case 5:
                    SortingTime1 = measureSortingTime5(data1, moves[0], comparisons[0]); //调用折半插入排序函数，返回排序时间，并记录数据移动次数和比较次数
                    SortingTime2 = measureSortingTime5(data2, moves[1], comparisons[1]);
                    SortingTime3 = measureSortingTime5(data3, moves[2], comparisons[2]);
                    cout << "折半插入排序结果：" << endl << endl; //输出排序结果
                    validChoice = true;
                    break;
                default:
                    cout << "选择无效的排序算法，请重新输入。" << endl << endl; //如果用户选择的排序算法无效，则输出错误提示
                    
                }
                validChoice = true; //将validChoice设为true，退出循环
            }


            else //如果输入的不是数字！
            {
                cout << "请输入有效的数字选项。" << endl;
                cin.clear();  // 清除错误状态
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } // 清空输入缓冲区

        }


        //输出分析结果！
        cout << "数据1排序结果：" << endl;
        OutPut(moves[0], comparisons[0], SortingTime1);
        cout << "数据2排序结果：" << endl;
        OutPut(moves[1], comparisons[1], SortingTime2);
        cout << "数据3排序结果：" << endl;
        OutPut(moves[2], comparisons[2], SortingTime3);
        printHorizontalLine();


        //询问是否继续进行分析！
        cout << "是否继续进行排序算法分析？(输入 'y' 继续，'n' 退出): ";
        cin >> continueSorting;
    }
    
    return 0; 
}
