#include<iostream>
#include<list>
#include<climits>
using namespace std;

typedef struct Prim {
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
}





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
		*(*(grpah1 + j) + i) = w;
	}
}//建立邻接矩阵





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








int minprim(prim* mc)
{
	int key = -1;
	int minWeight = INT_MAX;

	for (int i = 0; i < 5; i++)
	{
		if ((mc + i)->blackweight > 0 && (mc + i)->blackweight < minWeight)
		{
			minWeight = (mc + i)->blackweight;
			key = i;
		}
	}
	return key;
}//找到辅助数组中的最小的不为0 的权值









void creat___prim(prim*& mc, int**& grpah1, char*& graph, char x)
{
	int k = locat(graph, x);//寻找x的序号
	int w = first_adj(k, grpah1);
	for (int i = 0; i < 5; i++)
	{
		(mc + i)->blackweight = INT16_MAX;

	}//在这里初始化所有的的初始数组的权值为了防止当一个顶点所有临接点都拓展完了之后，扩展下一个顶点时未初始化辅助数组是，权值无法存入。
	while (w >= 0)
	{
		(mc + w)->blackweight = *(*(grpah1 + k) + w);
		(mc + w)->redpeak = *(graph + k);
		w = first_adj_deep(w, grpah1, k);
	}
	(mc + k)->blackweight = 0;
	for (int i = 1; i < 5; i++)
	{
		k = minprim(mc);//求出树中的下一个顶点
		cout << (mc + k)->redpeak << " " << *(graph + k) << endl;
		(mc + k)->blackweight = 0;
		w = first_adj(k, grpah1);
		while (w >= 0)
		{
			bool key = false;
			if (*(*(grpah1 + k) + w) < (mc + w)->blackweight && *(*(grpah1 + k) + w) > 0 || (mc + w)->blackweight < 0 && *(*(grpah1 + k) + w) > 0)
			{
				key = true;
				(mc + w)->blackweight = *(*(grpah1 + k) + w);
				(mc + w)->redpeak = *(graph + k);
			}
			w = first_adj_deep(w, grpah1, k);
		}
	}
}//最小生成树的实现代码



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
	}
	prim* msct = new prim[5];
	cout << endl;
	char x;
	cin >> x;//定义开始生成树的开始顶点
	creat___prim(msct, grpah1, graph, x);
}

