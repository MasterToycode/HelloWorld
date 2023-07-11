#define _CRT_SECURE_NO_WARNINGS
#define _ALLOW_COMPILER_AND_STL_VERSION_MISMATCH
#include <iostream>
#include<stack>
#include<queue>
#include<climits>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
#define N 20
#define M 2*N-1
#define MAX 9999
typedef struct {
	int weight;
	int parent;
	int lchild;
	int rchild;
}HTNode, HuffmanTree[M + 1];
void CrtHuffmantree(HuffmanTree ht, int w[], int n);
void Select(HuffmanTree ht, int n, int* s1, int* s2);
void CrtHuffmanCode(HuffmanTree ht, int n);
int main() {
	int i, w[100], n;
	cin >> n;
	for (i = 0; i < n; i++)
		cin >> w[i];
	//char str[5] = { 'c','s','e','a','t' };
	HuffmanTree ht;
	CrtHuffmantree(ht, w, n);
	//cout << "哈夫曼树各节点的值：" << endl;
	//for (i = 1; i <= 2*n-1; i++)
	//	cout << ht[i].weight << " ";
	cout << endl;
	CrtHuffmanCode(ht, n);

}
void CrtHuffmantree(HuffmanTree ht, int w[], int n) {
	//构建哈夫曼树ht[M+1],w[]为n个权值
	int i;
	for (i = 1; i <= n; i++) {
		ht[i].weight = w[i - 1];
		ht[i].parent = 0;
		ht[i].lchild = 0;
		ht[i].rchild = 0;
	} //将前n个元素即为叶子节点初始化
	int m = 2 * n - 1;
	for (i = n + 1; i <= m; i++) {
		ht[i].weight = 0;
		ht[i].parent = 0;
		ht[i].lchild = 0;
		ht[i].rchild = 0;
	} //将后面n-1个元素初始化为0
	//创建非叶子结点
	int s1, s2;
	for (i = n + 1; i <= m; i++) {
		Select(ht, i - 1, &s1, &s2);
		ht[i].weight = ht[s1].weight + ht[s2].weight;
		ht[s1].parent = i;
		ht[s2].parent = i;
		ht[i].lchild = s1;
		ht[i].rchild = s2;
	}
}
void Select(HuffmanTree ht, int n, int* s1, int* s2) {
	//在ht[1]到ht[n]之间选择两个parent=0并且weight最小的两个节点
	//将序号赋给s1,s2
	int i, min1 = MAX, min2 = MAX;
	*s1 = 0, * s2 = 0;
	for (i = 1; i <= n; i++) {
		if (ht[i].parent == 0) {
			if (ht[i].weight < min1) {
				min2 = min1;
				*s2 = *s1;
				min1 = ht[i].weight;
				*s1 = i;
			}
			else if (ht[i].weight < min2) {
				min2 = ht[i].weight;
				*s2 = i;
			}
		}
	}

}
void CrtHuffmanCode(HuffmanTree ht, int n) {
	//从叶子到根，逆向求每个叶子结点的哈夫曼编码
	char* cd;
	cd = (char*)malloc(n * sizeof(char));
	cd[n - 1] = '\0';
	for (int i = 1; i <= n; i++) {
		int start = n - 1, c = i, p = ht[i].parent;
		while (p != 0) {
			--start;
			if (ht[p].lchild == c)
				cd[start] = '0';
			else
				cd[start] = '1';
			c = p;
			p = ht[p].parent;
		}
		//cout << str[i-1] << "的编码是：";
		for (int j = start; j < n; j++) {
			if (cd[j] == '0' || cd[j] == '1')
				cout << cd[j];
		}
		cout << endl;
	}
	free(cd);
}