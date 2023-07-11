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
}//�����ڽӾ���





int  first_adj(int a, int**& grpah1)
{
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		if (*(*(grpah1 + a) + i) != INT16_MAX) return i;
		else return -1;
	}
}//Ѱ�Ҷ�����ڽӵ�






// �������ƣ�deep
// ������
// 1. graph1: int���͵Ķ�άָ�룬�洢ͼ���ڽӾ���
// 2. graph: char���͵�ָ�룬�洢ͼ�Ľڵ���Ϣ
// 3. k: int���͵ı�������ʾ��ǰ�ڵ�ı��
// 4. symbol: int���͵�ָ�룬��ʾÿ���ڵ��Ƿ񱻷��ʹ��ı��
// ����ֵ����
// ���ܣ��Խڵ�k�����������������������������
void deep(int**& graph1, char*& graph, int k, int*& symbol)
{
	// ����ڵ�k��δ�����ʹ���������ڵ���Ϣ�����Ϊ�ѷ���
	if (symbol[k] == 0)
	{
		cout << *(graph + k) << " ";
		symbol[k] = 1;
	}
	// �����ڵ�k�������ھӽڵ㣬����ھӽڵ㻹δ�����ʹ���������ڵ���Ϣ�����Ϊ�ѷ���
	int w = first_adj(k, graph1);
	while (w >= 0)
	{
		if (symbol[w] == 0)cout << *(graph + k) << " ";
		w = first_adj(w, graph1);
	}
}




/*
 * @brief ��ͼ���������������
 *
 * @param grpah1 ͼ���ڽӾ���
 * @param graph ͼ�нڵ������
 * @param symbol ��¼�ڵ��Ƿ񱻷��ʹ�������
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
	 graph = new char[n];//�洢�������Ϣ�ľ���
	 grpah1 = new int* [n];
	for (int k = 0; k < m; k++)
	{
		*(grpah1 + k) = new int[m];//�����ڽӾ���
	}
}





// ����ڽӾ���
void output_V(char*& graph, int**& grpah1, int n, int m)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			// �����ǰ�ڵ��ֵΪ����������"��"
			if (*(*(grpah1 + i) + j) == INT16_MAX)
				cout << "��" << " ";
			else
				cout << *(*(grpah1 + i) + j) << " "; // ��������ڵ��ֵ
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

