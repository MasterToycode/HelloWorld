#include<iostream>
#include<list>
#include<climits>
#include<queue>
using namespace std;
typedef struct VList 
{
	int weight;//ͼ�еĻ���Ȩֵ
	int number;//�����ڽӱ��е��ڽӽڵ�����
	VList* next;
}Vlist, * Vlist1;//�����ڽӱ����������������Ϣ






typedef struct Vnode 
{
	char peak;//�ַ�����Ķ��㣬����ͼ�еĶ������Ϣ
	Vlist* firstnext;//ָ��ö����һ�ڽӵ�
}VNode, * VNode1;//������ͷ�ڵ��˳�����ݽṹ���������������Ϣ






void creat_adjlist(int i, int weight1, int number1, VNode1& p)
{
	Vlist1 r = new Vlist;
	r->number = number1;
	r->weight = weight1;
	r->next = (p + i)->firstnext;
	(p + i)->firstnext = r;
}//�����ڽӱ��еĵ�i������







int locat_peak(VNode1& p, char w)
{
	for (int i = 0; i < 5; i++)
	{
		if (w == (p + i)->peak)
		{
			return i;
		}
	}//Ѱ�Ҷ����Ӧ�����

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
		cin >> v1 >> v2 >> w;//����ͼ���߼���Ϣ��Ȩֵ
		i = locat_peak(p, v1);
		j = locat_peak(p, v2);
		creat_adjlist(i, w, j, p);
		creat_adjlist(j, w, i, p);//����ע�⣬v1��v2 �����ǣ���Ҫ�Ե�i��j�������н����ԳƵ�
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
}//�����ڽӱ�ĺ���






//�ú���ʵ��ͼ�Ĺ����������������pΪͼ���ڽӱ��ʾ��������ÿ���ڵ�����˸ö������Ϣ�͵�һ�����ߵ�ָ��
void width_fun(VNode1 p)
{
	int symbol[5] = { 0, 0, 0, 0, 0 }; //������飬���ڼ�¼ÿ�������Ƿ��Ѿ������ʹ�
	queue<int> Q; //�����м���У����ڴ����Ѿ����ʹ����ڽӵ�
	for (int k = 0; k < 5; k++) //����ÿ�����㣬�����й����������
	{
		if (symbol[k] == 0) //����ö��㻹û�б����ʹ�
		{
			cout << (p + k)->peak << " "; //����ö������Ϣ
			symbol[k] = 1; //���ö�����Ϊ�Ѿ����ʹ�
			Q.push(k); //���ö��������
			while (!Q.empty()) //�Ըö�����ڽӵ���з���
			{
				int w = Q.front(); //ȡ�����׶���
				Q.pop(); //�������׶���
				Vlist1 cur = (p + w)->firstnext; //�ҵ��ö���ĵ�һ������
				for (; cur != NULL; cur = cur->next) //����Ѱ�Ҹö�����ڽӵ�
				{
					int v = cur->number; //ȡ���ڽӵ�ı��
					if (symbol[v] == 0) //������ڽӵ㻹û�б����ʹ�
					{
						cout << (p + v)->peak << " "; //������ڽӵ����Ϣ
						symbol[v] = 1; //�����ڽӵ���Ϊ�Ѿ����ʹ�
						Q.push(v); //�����ڽӵ�����У�������������ڽӵ�ķ���
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