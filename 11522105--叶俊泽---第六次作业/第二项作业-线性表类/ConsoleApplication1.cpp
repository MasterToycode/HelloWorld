#include"Linear.h"
int main() {
	Linear list(10);
	cout << "请您按照要求向线性表中添加数据！" << endl;
	char chioce='/0';
	while (chioce!='n'&&chioce!='N')
	{
		int x;
		cout << "请您输入数据：";
		cin >> x;
		list.Add(int(x));
		cout << "您是否愿意继续添加数据？（y or n）" << endl;
		cin >> chioce;
	}
	list.Output();
}