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
//ʵ���������ĸ�������





int  locat(char*& grpah, char v)
{
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		if (v == *(grpah + i))
			return i;
	}
}//�ҵ���Ӧ�ڵ�����





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
	}
}//�����ڽӾ���(youixangde)






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
}//�������ж������ȵĺ���







void tuopupaixu(int*& f, char*& grpah, int**& grpah1)
{
	int count = 0;//������Ľڵ����
	Find_indgreaa(f, grpah, grpah1);
	stack<char>s;//Ϊ�˱����ظ�������Ϊ0�Ľڵ㣬���ǽ���һ����ʱ��ջ�������Ϊ0�Ľڵ�
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		if (*(f + i) == 0)
		{
			s.push(*(grpah + i));
		}
	}//�Ը���ջ���г�ʼ��
	for (; s.size() != 0;)
	{
		i = locat(grpah, s.top());//�ҵ����Ϊ0�Ľڵ�����
		cout << *(grpah + i) << " "; ++count;
		s.pop();//�������Ϊ0�Ľڵ�
		int w = first_adj(i, grpah1);//�����i����ŵ��ڽӵ�����
		while (w >= 0)
		{
			*(f + w) = *(f + w) - 1;//�Ե�i���ڵ�������ڽӵ����ȼ�һ
			if (*(f + w) == 0)
			{
				s.push(*(grpah + w));
			}
			w = first_adj_deep(w, grpah1, i);
		}//�ҵ����еĵ�i���ڵ���ڽӵ㣬�������ִ�в���
	}
	cout << endl;
	if (count < 5)
		cout << "��ͼΪһ��������л�ͼ " << endl;
	else cout << "��ͼΪһ�������޻�ͼ" << endl;
}//���������ʵ�ֺ���







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
	}//����ڽӾ���


	int* f = new int[n];//���崢��������������ڵ�����
	tuopupaixu(f, graph, grpah1);
}


