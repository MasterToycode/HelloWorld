#include"h1.h"
void swap(int& a, int& b)
{
    int c = a;
    a = b;
    b = c;
}
// 堆调整函数，将以s为根的子树调整为小根堆
void HeapAdjust(vector<int>& L, int s, int m, long long int& moves, long long int& comparisons)
{
    // 保存当前根节点的值
    int cr = L[s];
    // 从左子节点开始遍历
    for (int i = 2 * s + 1; i <= m; i = 2 * i + 1)
    {
        // 找出左右子节点中值较小的节点
        if (i < m && L[i] > L[i + 1])
        {
            i++;
            comparisons++;// 记录比较次数
        }

        // 如果当前根节点已经小于等于子节点，则跳出循环
        if (cr <= L[i]) break;


        // 将子节点上移
        L[s] = L[i];
        // 更新当前根节点的位置
        s = i;
        moves++;//记录移动次数
    }

    // 将原来的根节点放到新的位置上
    L[s] = cr;
}



// 堆排序函数
void HeapSort(vector<int>& L, int len, long long int& moves, long long int& comparisons)
{
    // 构建初始堆
    for (int i = len / 2 - 1; i >= 0; i--) // 从最后一个非叶子节点开始调整堆
        HeapAdjust(L, i, len - 1, moves, comparisons); // 调整堆结构
    // 将堆顶元素与堆底元素交换，并重新调整堆


    for (int i = len - 1; i >= 0; i--) // 堆的大小每次减1
    {
        //cout << L[0] << " "; // 输出堆顶元素
        if (i) // 当堆的大小不为0时，进行交换和调整堆
        {
            swap(L[0], L[i]); // 将堆顶元素与堆底元素交换

            moves++;//记录移动次数！

            HeapAdjust(L, 0, i - 1, moves, comparisons); // 调整堆结构
        }
    }
}



double measureSortingTime2(vector<int> arr, int len, long long int& moves, long long int& comparisons)
{
    auto start = chrono::high_resolution_clock::now();
    HeapSort(arr, len, moves, comparisons);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
    return duration.count(); // 返回执行时间（秒）
}

