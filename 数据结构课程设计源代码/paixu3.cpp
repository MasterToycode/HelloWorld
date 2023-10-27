#include"h1.h"
// 快速排序的核心算法，将序列分为两部分，左边比中心点小，右边比中心点大
int Quick_Sort(vector<int>& L, int low, int high, long long int& moves, long long int& comparisons)
{
    // 以第一个元素为中心点
    int key = L[low];
    while (low < high)
    {
        // 从右往左找到第一个比中心点小的元素
        while (low < high && L[high] >= key)
        {
            high--;
            comparisons++;
        }
        // 将该元素放到中心点左边
        L[low] = L[high];
        moves++;

        // 从左往右找到第一个比中心点大的元素
        while (low < high && L[low] <= key)
        {
            low++;
            comparisons++;
        }
        // 将该元素放到中心点右边
        L[high] = L[low];
        moves++;
    }
    // 将中心点放到最终位置


    L[high] = key;
    moves++;
    // 返回中心点的位置

    return low;
}


// 快速排序的递归函数
void QuickSort(vector<int>& L, int low, int high, long long int& moves, long long int& comparisons)
{
    if (low < high)
    {
        // 将序列分为两部分
        int pivotloc = Quick_Sort(L, low, high, moves, comparisons);
        // 对左半部分进行排序
        QuickSort(L, low, pivotloc - 1, moves, comparisons);
        // 对右半部分进行排序
        QuickSort(L, pivotloc + 1, high, moves, comparisons);
    }
}


double measureSortingTime3(vector<int> arr, int low, int high, long long int& moves, long long int& comparisons)
{
    auto start = chrono::high_resolution_clock::now();
    QuickSort(arr, low, high, moves, comparisons);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
    return duration.count(); // 返回执行时间（秒）
}

