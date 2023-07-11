#include<iostream>
#include<list>
#include<climits>
using namespace std;



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
	for (i = 0; i < n; i++)
	{
		cin >> *(grpah + i);
	}

	i = 0;
	int j = 0;
	int k = 0;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
			*(*(grpah1 + i) + j) = INT16_MAX;
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





int  first_adj(int a, int**& grpah1)
{
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		if (*(*(grpah1 + a) + i) != INT16_MAX) return i;
		else return -1;
	}
}//寻找顶点的邻接点






// 函数名称：deep
// 参数：
// 1. graph1: int类型的二维指针，存储图的邻接矩阵
// 2. graph: char类型的指针，存储图的节点信息
// 3. k: int类型的变量，表示当前节点的编号
// 4. symbol: int类型的指针，表示每个节点是否被访问过的标记
// 返回值：无
// 功能：对节点k进行深度优先搜索，并输出遍历结果
void deep(int**& graph1, char*& graph, int k, int*& symbol)
{
	// 如果节点k还未被访问过，则输出节点信息并标记为已访问
	if (symbol[k] == 0)
	{
		cout << *(graph + k) << " ";
		symbol[k] = 1;
	}
	// 遍历节点k的所有邻居节点，如果邻居节点还未被访问过，则输出节点信息并标记为已访问
	int w = first_adj(k, graph1);
	while (w >= 0)
	{
		if (symbol[w] == 0)cout << *(graph + k) << " ";
		w = first_adj(w, graph1);
	}
}




/*
 * @brief 对图进行深度优先搜索
 *
 * @param grpah1 图的邻接矩阵
 * @param graph 图中节点的名称
 * @param symbol 记录节点是否被访问过的数组
 */
void deep_find(int**& grpah1, char*& graph, int*& symbol)
{
	int k = 0;
	for (k = 0; k < 5; k++)
	{
		if (symbol[k] == 0)
		{
			deep(grpah1, graph, k, symbol);
		}
	}
}








void initalsize_V(char*& graph, int**& grpah1, int n, int m)
{
	 graph = new char[n];//存储顶点的信息的矩阵
	 grpah1 = new int* [n];
	for (int k = 0; k < m; k++)
	{
		*(grpah1 + k) = new int[m];//建立邻接矩阵
	}
}





// 输出邻接矩阵
void output_V(char*& graph, int**& grpah1, int n, int m)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			// 如果当前节点的值为无穷大，则输出"∞"
			if (*(*(grpah1 + i) + j) == INT16_MAX)
				cout << "∞" << " ";
			else
				cout << *(*(grpah1 + i) + j) << " "; // 否则输出节点的值
		}
		cout << endl;
	}
}





int main()
{
	int n;
	int m;
	cin >> n >> m;
	char* graph;
	int** grpah1;
	initalsize_V(graph, grpah1, n, m);
	creat_graph(n, m, graph, grpah1);
	output_V(graph, grpah1, n, m);
	int  symbol[5] = { 0,0,0,0,0 };
	int* p = symbol;
	deep_find(grpah1, graph, p);
}

