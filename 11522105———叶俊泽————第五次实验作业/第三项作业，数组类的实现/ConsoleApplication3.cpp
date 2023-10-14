#include"Array.h"
void printHorizontalLine()
{
	string horizontalLine(100, '-');
    cout << horizontalLine << endl << endl;;
}
void Explanation()
{
    cout << "这是一个简单的数组类实现了数组的各项最基本的操作！现有说明如下：" << endl
        << "1.显示  2.排序  3.插入  4.删除  5.查找 6.退出" << endl;
}
int main() 
{
        Explanation();
        int choice;
        int x;
        cout << "请您输入数组的长度大小(<=10)：";
        cin >> x;
        cout << endl;
        Array array(x);
        cout << "请您输入数组的各个元素：";
        array.IuPut();
        array.Sort();
        printHorizontalLine();
        while (true) 
        {
            cout << "请输入您要进行的操作：" << endl;
            cout << "1. 显示  2. 排序  3. 插入  4. 删除  5. 查找  6. 退出" << endl << endl;
            cin >> choice;
            cout << endl;

            switch (choice) 
            {
            case 1: 
            {
                array.Display();
                printHorizontalLine();
                break;
            }
            case 2: 
            {
                char y;
                cout << "输入 'a' 升序排序，输入 'd' 降序排序，请您正确输入: ";
                cin >> y;
                array.Sort(y);
                array.Display();
                printHorizontalLine();
                break;
            }
            case 3: 
            {
                int number;
                cout << "请您输入您想要插入的数据：";
                cin >> number;
                array.Insert(number);
                array.Display();
                printHorizontalLine();
                break;
            }
            case 4: 
            {
                int element;
                cout << "请您输入您想要删除的数据：";
                cin >> element;
                array.Delete(element);
                array.Display();
                printHorizontalLine();
                break;
            }
            case 5: 
            {
                int element;
                cout << "请您输入您想要查找的数据：";
                cin >> element;
                int location = array.Search(element);
                if (location == -1) 
                {
                    cout << "数组中没有您想要的数据！" << endl;
                }
                else 
                {
                    cout << "您想要查询的数据位置为：" << location << endl;
                }
                break;
            }
            case 6: 
            {
                return 0; 
            }
            default:
                cout << "无效的选择，请重新输入：" << endl;
            }
        }
 }

