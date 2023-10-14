#include"head.h"
#include"Matrix.h"

void printHorizontalLine()
{
    string horizontalLine(50, '-');
    cout << horizontalLine << endl;
}

int main() 
{
    char choice;

    do {
        int rows, cols;
        cout << "Please input the dimension of the Matrix：";
        cin >> rows >> cols;

        Matrix matrix(rows, cols); // 创建Matrix对象，传入行数和列数
        matrix.InitializeMatrix(); // 调用成员函数分配矩阵内存和输入矩阵元素

        printHorizontalLine();
        cout << "请选择操作:" << endl;
        cout << "1. 矩阵数乘" << endl;
        cout << "2. 矩阵转置" << endl;
        cout << "3. 矩阵旋转" << endl;
        int operation;
        cin >> operation;

        switch (operation) {
        case 1:
            matrix.Multiply();
            printHorizontalLine();
            break;
        case 2:
            matrix.rotate90DegreesClockwise();
            matrix.OutPut();
            printHorizontalLine();
            // 调用矩阵转置函数
            break;
        case 3:
            matrix.Rotate90DegreesClockwise();
            matrix.OutPut();
            printHorizontalLine();
            // 调用矩阵旋转函数
            break;
        default:
            cout << "无效的操作。" << endl;
        }
        // 询问用户是否继续
        cout << "是否继续操作？(y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');
    return 0;
}
