#include<iostream>
using namespace std;
void swap(int& a, int& b)
{
    int c = a;
    a = b;
    b = c;
}


void input(int*& L)
{
    int i = 0;
    for (i = 0; i < 8; i++)
    {
        cin >> *(L + i);
    }
}



// 堆调整函数，将以s为根的子树调整为小根堆
void HeapAdjust(int* L, int s, int m)
{
    // 保存当前根节点的值
    int cr = L[s];
    // 从左子节点开始遍历
    for (int i = 2 * s + 1; i <= m; i = 2 * i + 1)
    {
        // 找出左右子节点中值较小的节点
        if (i < m && L[i] > L[i + 1]) i++;
        // 如果当前根节点已经小于等于子节点，则跳出循环
        if (cr <= L[i]) break;
        // 将子节点上移
        L[s] = L[i];
        // 更新当前根节点的位置
        s = i;
    }
    // 将原来的根节点放到新的位置上
    L[s] = cr;
}



// 堆排序函数
void HeapSort(int* L, int len)
{
    // 构建初始堆
    for (int i = len / 2 - 1; i >= 0; i--) // 从最后一个非叶子节点开始调整堆
        HeapAdjust(L, i, len - 1); // 调整堆结构
    // 将堆顶元素与堆底元素交换，并重新调整堆
    for (int i = len - 1; i >= 0; i--) // 堆的大小每次减1
    {
        cout << *(L) << " "; // 输出堆顶元素
        if (i) // 当堆的大小不为0时，进行交换和调整堆
        {
            swap(L[0], L[i]); // 将堆顶元素与堆底元素交换
            HeapAdjust(L, 0, i - 1); // 调整堆结构
        }
    }
}




void output(int*& L)
{
    int i = 0;
    for (i = 0; i < 8; i++)
    {
        cout << *(L + i) << " ";
    }
    cout << endl;
}




int main()
{
    int* L = new int[8];
    input(L);
    HeapSort(L, 8);
    cout << endl;
}