#include<iostream>
#include<list>
#include<climits>
#include<stack>
using namespace std;
// 定义一个函数 locat，返回 v 在 graph 中的索引位置
int locat(char*& graph, char v)
{
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		// 如果找到了 v，则返回索引位置 i
		if (v == *(graph + i))
			return i;
	}
}





// 创建邻接矩阵表示的图
void creat_graph(int n, int m, char*& grpah, int**& grpah1)
{
	// 读入顶点信息
	for (int i = 0; i < n; i++)
	{
		cin >> *(grpah + i);
	}

	// 初始化邻接矩阵
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			*(*(grpah1 + i) + j) = INT16_MAX;
	}

	// 读入边信息并将其存入邻接矩阵中
	char v1, v2;
	int w;
	for (int k = 0; k < m; k++)
	{
		cin >> v1 >> v2 >> w;
		int i = locat(grpah, v1); // 找到边的起点对应的顶点下标
		int j = locat(grpah, v2); // 找到边的终点对应的顶点下标
		*(*(grpah1 + i) + j) = w; // 存入邻接矩阵中
		*(*(grpah1 + j) + i) = w;
	}
}





int  first_adj(int a, int** grpah1)
{
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		if (*(*(grpah1 + a) + i) != '∞')  return i;
	}
	return -1;
}//寻找顶点的邻接点






int first_adj_deep(int b, int** grpah1, int  c)
{

	for (int i = b + 1; i < 5; i++)
	{
		if (*(*(grpah1 + c) + i) != '∞') return i;

	}
	return -1;
}//寻找顶点的所有邻接点






//迪杰斯特拉算法的实现
//求有（无）向网G的v0顶点到其余顶点v的最短路径
void ShortPath_DIJ(int** grpah1, char vo, int*& D, int*& S, int*& path, char*& grpah)
{
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		*(S + i) = 0;//初始化S辅助变量，所有的节点都为曾被确定最短路径
		*(D + i) = *(*(grpah1 + locat(grpah, vo)) + i);////将v0到各个终点的最终路径长度初始化为权值
		if (*(D + i) < INT16_MAX)
			*(path + i) = 0;
		else *(path + i) = -1;
		//记录从源点v0到终点vi的当前最短
			//路径上vi的直接前驱顶点序号。其初值为：如果v0到vi有
			//弧，则path[i]为vo，否则为 - 1。
		//邻接点为0
	}
	*(D + locat(grpah, vo)) = 0;
	*(S + locat(grpah, vo)) = 1;//vo点进入S集，集，vo点已经被访问过了
	//初始化结束
	//开始主循环，每次求得v0到某个顶点v的最短路径，将v加到S集
	for (i = 1; i < 5; i++)
	{
		int min = INT16_MAX;
		int w = 0;
		int v = 0;
		for (w = 0; w < 5; w++)
		{
			if (!*(S + w) && *(D + w) < min)
			{
				v = w;
				min = *(D + v);//找出和vo之间存在弧的顶点且长度最小的
			}
		}
		*(S + v) = 1;//v所找的节点入S集合
		//修改从vo出发的最短路径的长度
		//更新从v0出发到集合V-S上所有顶点的最短路径长度
		for (w = 0; w < 5; w++)
		{
			if (!*(S + w) && min + *(*(grpah1 + v) + w) < *(D + w))
			{
				*(D + w) = min + *(*(grpah1 + v) + w);
				// w不属于S集且v0→v→w的距离＜目前v0→w的距离
				*(path + w) = v;
			}
		}
	}



	for (i = 0; i < 5; i++)
	{
		if (i == locat(grpah, vo))cout << "第" << i << "号节点为源点" << endl;
		else cout << "节点" << vo << "到" << "节点" << i << "的最短路径的长度为：" << " " << *(D + i) << endl;
	}//输出最短路径的长度
}







int main()
{
	cout << "请输入有关该图的有效信息：" << endl;
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
	cout << endl;
	cout << "邻接矩阵如下：" << endl;
	for (i = 0; i < 5; i++)
	{
		cout << *(graph + i) << "   ";
		for (j = 0; j < 5; j++)
		{
			if (*(*(grpah1 + i) + j) == INT16_MAX)cout << "∞" << " ";
			else cout << *(*(grpah1 + i) + j) << " ";
		}
		cout << endl;//输出邻接矩阵
	}
	int* D = new int[m];//定义辅助变量D。它的每个分量D[i]表示当前所找到
	//的从源点v0到每个终点vi的最短路径的长度。
	int* S = new int[m];//定义辅助变量，记录从源点v0到终点vi是否已被确定最短路径长度，
	//true表示确定，false表示尚未确定
	int* path = new int[m];//记录从源点v0到终点vi的当前最短
	//路径上vi的直接前驱顶点序号。其初值为：如果v0到vi有
	 //弧，则Path[i]为v0，否则为 - 1。

	cout << "请输入查找最短路径的源点" << endl;
	char vo;
	cin >> vo;//输入最短路径的源点
	ShortPath_DIJ(grpah1, vo, D, S, path, graph);
}