#include<iostream>
#include<list>
#include<climits>
using namespace std;

typedef struct Prim {
	char redpeak;
	int blackweight;
}prim;
//ʵ���������ĸ�������



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
			*(*(grpah1 + i) + j) = '��';
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





int  first_adj(int a, int** grpah1)
{
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		if (*(*(grpah1 + a) + i) != '��')  return i;
	}
	return -1;
}//Ѱ�Ҷ�����ڽӵ�






int first_adj_deep(int b, int** grpah1, int  c) {

	for (int i = b + 1; i < 5; i++)
	{
		if (*(*(grpah1 + c) + i) != '��') return i;

	}
	return -1;
}//Ѱ�Ҷ���������ڽӵ�








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
}//�ҵ����������е���С�Ĳ�Ϊ0 ��Ȩֵ









void creat___prim(prim*& mc, int**& grpah1, char*& graph, char x)
{
	int k = locat(graph, x);//Ѱ��x�����
	int w = first_adj(k, grpah1);
	for (int i = 0; i < 5; i++)
	{
		(mc + i)->blackweight = INT16_MAX;

	}//�������ʼ�����еĵĳ�ʼ�����ȨֵΪ�˷�ֹ��һ�����������ٽӵ㶼��չ����֮����չ��һ������ʱδ��ʼ�����������ǣ�Ȩֵ�޷����롣
	while (w >= 0)
	{
		(mc + w)->blackweight = *(*(grpah1 + k) + w);
		(mc + w)->redpeak = *(graph + k);
		w = first_adj_deep(w, grpah1, k);
	}
	(mc + k)->blackweight = 0;
	for (int i = 1; i < 5; i++)
	{
		k = minprim(mc);//������е���һ������
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
}//��С��������ʵ�ִ���



int main()
{
	int n;
	int m;
	cin >> n >> m;
	char* graph = new char[n];//�洢�������Ϣ�ľ���
	int** grpah1 = new int* [n];
	int symbol[5] = { 0,0,0,0,0 };
	int* p = symbol;
	for (int k = 0; k < m; k++)
	{
		*(grpah1 + k) = new int[m];//�����ڽӾ���
	}
	creat_graph(n, m, graph, grpah1);
	int i = 0;
	int j = 0;
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			if (*(*(grpah1 + i) + j) == '��')cout << "��" << " ";
			else cout << *(*(grpah1 + i) + j) << " ";
		}
		cout << endl;
	}
	prim* msct = new prim[5];
	cout << endl;
	char x;
	cin >> x;//���忪ʼ�������Ŀ�ʼ����
	creat___prim(msct, grpah1, graph, x);
}

