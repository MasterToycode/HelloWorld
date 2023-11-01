#include"Student.h"
void ReadStringFromConsole(char* buffer, int bufferSize) 
{
    char c = 0;
    int i = 0;
    while (i < bufferSize) 
    {
        scanf("%c", &c);
        // 如果遇到换行符或回车符，停止读取
        if (c == '\n')
        {
            break;
        }
        buffer[i] = c;
        i++;
    }

    buffer[i] = '\0'; // 手动添加终止符
}

void ReadIntegersFromConsole(int* buffer, int bufferSize) 
{
    int num;
    int i = 0;
    while (i < bufferSize) 
    {
        string input;
        getline(cin, input);
        if (input.empty())
        {
            break;  // 当用户按回车键时，退出输入循环
        }
        if (stringstream(input) >> num)
        {
            buffer[i] = num;
            i++;
        }
    }
    buffer[i+1] = {'\0'};
}


int main() 
{
    char flag = 'y';
    long int a = 0;
    char b[50] = { '\0' };
    char c[50] = { '\0' };
    char d[50] = { '\0' };
    char e[50] = { '\0' };
    char f[50] = { '\0' };
    float x = 0;
    while (flag=='y')
    {
        cout << "请输入这个学生个课程及其分数信息（例如：2016116101 张三 男 计科161 COST3114 C++ 90）:" << endl;
        cin >> a;
        cin.get(); // 等待回车键
        ReadStringFromConsole(b, 50);
        ReadStringFromConsole(c, 50);
        ReadStringFromConsole(d, 50);
        ReadStringFromConsole(e, 50);
        ReadStringFromConsole(f, 50);
        cin >> x;
        Student student(a, b, c, d);
        Scource scource(e,f);
        Sscore score(x);
        cout << "学生课程成绩信息如下:" << endl;
        student.Student_show();
        scource.Scource_show();
        score.Sscore_show();
        cout << "继续输入课程成绩吗?(y/n)";
        cin >> flag;
       // cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}