#include<iostream>
#include<list>
#include<climits>
#include<stack>
using namespace std;
// ����һ������ locat������ v �� graph �е�����λ��
int locat(char*& graph, char v)
{
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		// ����ҵ��� v���򷵻�����λ�� i
		if (v == *(graph + i))
			return i;
	}
}





// �����ڽӾ����ʾ��ͼ
void creat_graph(int n, int m, char*& grpah, int**& grpah1)
{
	// ���붥����Ϣ
	for (int i = 0; i < n; i++)
	{
		cin >> *(grpah + i);
	}

	// ��ʼ���ڽӾ���
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			*(*(grpah1 + i) + j) = INT16_MAX;
	}

	// �������Ϣ����������ڽӾ�����
	char v1, v2;
	int w;
	for (int k = 0; k < m; k++)
	{
		cin >> v1 >> v2 >> w;
		int i = locat(grpah, v1); // �ҵ��ߵ�����Ӧ�Ķ����±�
		int j = locat(grpah, v2); // �ҵ��ߵ��յ��Ӧ�Ķ����±�
		*(*(grpah1 + i) + j) = w; // �����ڽӾ�����
		*(*(grpah1 + j) + i) = w;
	}
}





int  first_adj(int a, int** grpah1)
{
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		if (*(*(grpah1 + a) + i) != '��')  return i;
	}
	return -1;
}//Ѱ�Ҷ�����ڽӵ�






int first_adj_deep(int b, int** grpah1, int  c)
{

	for (int i = b + 1; i < 5; i++)
	{
		if (*(*(grpah1 + c) + i) != '��') return i;

	}
	return -1;
}//Ѱ�Ҷ���������ڽӵ�






//�Ͻ�˹�����㷨��ʵ��
//���У��ޣ�����G��v0���㵽���ඥ��v�����·��
void ShortPath_DIJ(int** grpah1, char vo, int*& D, int*& S, int*& path, char*& grpah)
{
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		*(S + i) = 0;//��ʼ��S�������������еĽڵ㶼Ϊ����ȷ�����·��
		*(D + i) = *(*(grpah1 + locat(grpah, vo)) + i);////��v0�������յ������·�����ȳ�ʼ��ΪȨֵ
		if (*(D + i) < INT16_MAX)
			*(path + i) = 0;
		else *(path + i) = -1;
		//��¼��Դ��v0���յ�vi�ĵ�ǰ���
			//·����vi��ֱ��ǰ��������š����ֵΪ�����v0��vi��
			//������path[i]Ϊvo������Ϊ - 1��
		//�ڽӵ�Ϊ0
	}
	*(D + locat(grpah, vo)) = 0;
	*(S + locat(grpah, vo)) = 1;//vo�����S��������vo���Ѿ������ʹ���
	//��ʼ������
	//��ʼ��ѭ����ÿ�����v0��ĳ������v�����·������v�ӵ�S��
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
				min = *(D + v);//�ҳ���vo֮����ڻ��Ķ����ҳ�����С��
			}
		}
		*(S + v) = 1;//v���ҵĽڵ���S����
		//�޸Ĵ�vo���������·���ĳ���
		//���´�v0����������V-S�����ж�������·������
		for (w = 0; w < 5; w++)
		{
			if (!*(S + w) && min + *(*(grpah1 + v) + w) < *(D + w))
			{
				*(D + w) = min + *(*(grpah1 + v) + w);
				// w������S����v0��v��w�ľ��룼Ŀǰv0��w�ľ���
				*(path + w) = v;
			}
		}
	}



	for (i = 0; i < 5; i++)
	{
		if (i == locat(grpah, vo))cout << "��" << i << "�Žڵ�ΪԴ��" << endl;
		else cout << "�ڵ�" << vo << "��" << "�ڵ�" << i << "�����·���ĳ���Ϊ��" << " " << *(D + i) << endl;
	}//������·���ĳ���
}







int main()
{
	cout << "�������йظ�ͼ����Ч��Ϣ��" << endl;
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
	cout << endl;
	cout << "�ڽӾ������£�" << endl;
	for (i = 0; i < 5; i++)
	{
		cout << *(graph + i) << "   ";
		for (j = 0; j < 5; j++)
		{
			if (*(*(grpah1 + i) + j) == INT16_MAX)cout << "��" << " ";
			else cout << *(*(grpah1 + i) + j) << " ";
		}
		cout << endl;//����ڽӾ���
	}
	int* D = new int[m];//���帨������D������ÿ������D[i]��ʾ��ǰ���ҵ�
	//�Ĵ�Դ��v0��ÿ���յ�vi�����·���ĳ��ȡ�
	int* S = new int[m];//���帨����������¼��Դ��v0���յ�vi�Ƿ��ѱ�ȷ�����·�����ȣ�
	//true��ʾȷ����false��ʾ��δȷ��
	int* path = new int[m];//��¼��Դ��v0���յ�vi�ĵ�ǰ���
	//·����vi��ֱ��ǰ��������š����ֵΪ�����v0��vi��
	 //������Path[i]Ϊv0������Ϊ - 1��

	cout << "������������·����Դ��" << endl;
	char vo;
	cin >> vo;//�������·����Դ��
	ShortPath_DIJ(grpah1, vo, D, S, path, graph);
}