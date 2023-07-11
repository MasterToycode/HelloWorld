#include<iostream>
#include<list>
#include<climits>
#include<stack>
using namespace std;
typedef struct Prim
{
	char redpeak;
	int blackweight;
}prim;
//实现生成树的辅助数组





int  locat(char*& grpah, char v)
{
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		if (v == *(grpah + i))
			return i;
	}
}//找到对应节点的序号





void creat_graph(int n, int m, char*& grpah, int**& grpah1)
{
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		cin >> *(grpah + i);
	}

	i = 0;
	int j = 0;
	int k = 0;
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
			*(*(grpah1 + i) + j) = '∞';
	}
	char v1, v2;
	int w;
	i = j = 0;
	for (k = 0; k < 5; k++)
	{
		cin >> v1 >> v2 >> w;
		i = locat(grpah, v1);
		j = locat(grpah, v2);
		*(*(grpah1 + i) + j) = w;
	}
}//建立邻接矩阵(youixangde)






int  first_adj(int a, int** grpah1)
{
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		if (*(*(grpah1 + a) + i) != '∞')  return i;
	}
	return -1;
}//寻找顶点的邻接点








int first_adj_deep(int b, int** grpah1, int  c) {

	for (int i = b + 1; i < 5; i++)
	{
		if (*(*(grpah1 + c) + i) != '∞') return i;
	}
	return -1;
}//寻找顶点的所有邻接点








void Find_indgreaa(int*& f, char*& grpah, int**& grpah1)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < 5; i++)
	{
		*(f + i) = 0;
	}
	for (i = 0; i < 5; i++)
	{
		j = first_adj(i, grpah1);
		for (; j >= 0; j = first_adj_deep(j, grpah1, i))
		{
			for (int k = 0; k < 5; k++)
			{
				if (*(grpah + j) == *(grpah + k))  *(f + j) = *(f + j) + 1;
			}
		}
	}
}//查找所有顶点的入度的函数







void tuopupaixu(int*& f, char*& grpah, int**& grpah1)
{
	int count = 0;//对输出的节点计数
	Find_indgreaa(f, grpah, grpah1);
	stack<char>s;//为了避免重复检测入度为0的节点，我们建立一个临时的栈储存入度为0的节点
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		if (*(f + i) == 0)
		{
			s.push(*(grpah + i));
		}
	}//对辅助栈进行初始化
	for (; s.size() != 0;)
	{
		i = locat(grpah, s.top());//找到入度为0的节点的序号
		cout << *(grpah + i) << " "; ++count;
		s.pop();//弹出入度为0的节点
		int w = first_adj(i, grpah1);//定义第i个序号的邻接点的序号
		while (w >= 0)
		{
			*(f + w) = *(f + w) - 1;//对第i个节点的所有邻接点的入度减一
			if (*(f + w) == 0)
			{
				s.push(*(grpah + w));
			}
			w = first_adj_deep(w, grpah1, i);
		}//找到所有的第i个节点的邻接点，并对入度执行操作
	}
	cout << endl;
	if (count < 5)
		cout << "该图为一个有向的有环图 " << endl;
	else cout << "该图为一个有向无环图" << endl;
}//拓扑排序的实现函数







int main()
{
	int n;
	int m;
	cin >> n >> m;
	char* graph = new char[n];//存储顶点的信息的矩阵
	int** grpah1 = new int* [n];
	int symbol[5] = { 0,0,0,0,0 };
	int* p = symbol;
	for (int k = 0; k < m; k++)
	{
		*(grpah1 + k) = new int[m];//建立邻接矩阵
	}


	creat_graph(n, m, graph, grpah1);
	int i = 0;
	int j = 0;
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			if (*(*(grpah1 + i) + j) == '∞')cout << "∞" << " ";
			else cout << *(*(grpah1 + i) + j) << " ";
		}
		cout << endl;
	}//输出邻接矩阵


	int* f = new int[n];//定义储存数组用来储存节点的入度
	tuopupaixu(f, graph, grpah1);
}


