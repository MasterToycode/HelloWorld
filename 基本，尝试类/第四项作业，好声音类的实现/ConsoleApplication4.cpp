#include"Voice.h"

void printHorizontalLine()
{
	string horizontalLine(100, '-');
	cout << horizontalLine << endl << endl;;
}
int main() 
{
	char chioce;
	do
	{
		cout << "请您输入这次报名比赛的歌手人数（<=3)：";
		int number;
		cin >> number;
		getchar();
		Singer* singer = new Singer[number];
		for (int i = 0; i < number; i++) 
		{
			singer[i].Enroll();
		}
		cout << "报名歌手信息如下：" << endl;
		for (int i = 0; i < number; i++)
		{
			singer[i].Display();
		}
		printHorizontalLine();
		int number1;
		cout << "请输入需要修改的歌手: ";
		cin >> number1;
		singer[number1].Modify();
		cout << "修改后的歌手信息如下：" << endl;
		singer[number1].Display(); 
		printHorizontalLine();
		cout << "您是否愿意继续报名？(y or n)：";
		cin >> chioce;
	} while (chioce=='y'||chioce=='Y');
}