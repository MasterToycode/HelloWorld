#include<iostream>
#include<list>
#include<climits>
#include<queue>
using namespace std;
typedef struct VList 
{
	int weight;//图中的弧的权值
	int number;//储存邻接表中的邻接节点的序号
	VList* next;
}Vlist, * Vlist1;//建立邻接表所需的所有数据信息






typedef struct Vnode 
{
	char peak;//字符数组的顶点，储存图中的顶点的信息
	Vlist* firstnext;//指向该顶点第一邻接点
}VNode, * VNode1;//建立表头节点的顺序数据结构所需的所有数据信息






void creat_adjlist(int i, int weight1, int number1, VNode1& p)
{
	Vlist1 r = new Vlist;
	r->number = number1;
	r->weight = weight1;
	r->next = (p + i)->firstnext;
	(p + i)->firstnext = r;
}//建立邻接表中的第i个链表







int locat_peak(VNode1& p, char w)
{
	for (int i = 0; i < 5; i++)
	{
		if (w == (p + i)->peak)
		{
			return i;
		}
	}//寻找顶点对应的序号

}





void creat_Adjacency_List(VNode1& p)
{
	char v1, v2;
	int w;
	int k = 0;
	int i = 0;
	int j = 0;
	for (k = 0; k < 5; k++)
	{
		cin >> v1 >> v2 >> w;//输入图的逻辑信息和权值
		i = locat_peak(p, v1);
		j = locat_peak(p, v2);
		creat_adjlist(i, w, j, p);
		creat_adjlist(j, w, i, p);//这里注意，v1和v2 相邻是，需要对第i和j链表都进行建立对称的
	}
	for (int i = 0; i < 5; i++)
	{
		cout << (p + i)->peak << "    ";
		Vlist1 cur = (p + i)->firstnext;
		while (cur != NULL)
		{
			cout << cur->number << " " << cur->weight << "   ";
			cur = cur->next;
		}
		cout << endl;
	}
}//建立邻接表的函数






//该函数实现图的广度优先搜索，参数p为图的邻接表表示法，其中每个节点包含了该顶点的信息和第一条出边的指针
void width_fun(VNode1 p)
{
	int symbol[5] = { 0, 0, 0, 0, 0 }; //标记数组，用于记录每个顶点是否已经被访问过
	queue<int> Q; //建立中间队列，用于储存已经访问过的邻接点
	for (int k = 0; k < 5; k++) //对于每个顶点，都进行广度优先搜索
	{
		if (symbol[k] == 0) //如果该顶点还没有被访问过
		{
			cout << (p + k)->peak << " "; //输出该顶点的信息
			symbol[k] = 1; //将该顶点标记为已经访问过
			Q.push(k); //将该顶点入队列
			while (!Q.empty()) //对该顶点的邻接点进行访问
			{
				int w = Q.front(); //取出队首顶点
				Q.pop(); //弹出队首顶点
				Vlist1 cur = (p + w)->firstnext; //找到该顶点的第一条出边
				for (; cur != NULL; cur = cur->next) //不断寻找该顶点的邻接点
				{
					int v = cur->number; //取出邻接点的编号
					if (symbol[v] == 0) //如果该邻接点还没有被访问过
					{
						cout << (p + v)->peak << " "; //输出该邻接点的信息
						symbol[v] = 1; //将该邻接点标记为已经访问过
						Q.push(v); //将该邻接点入队列，方便后续对其邻接点的访问
					}
				}
			}
		}
	}
}





int main() 
{
	int n, m;
	cin >> n >> m;
	VNode1 p = new VNode[n];
	for (int i = 0; i < n; i++) 
	{
		cin >> (p + i)->peak;
		(p + i)->firstnext = NULL;
	}
	creat_Adjacency_List(p);
	width_fun(p);
}