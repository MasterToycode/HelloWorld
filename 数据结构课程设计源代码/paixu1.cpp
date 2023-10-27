#include"h1.h"
void shellsort(vector<int>& L, long long int& moves, long long int& comparisons)
{
    int dk = L.size() / 2; // 初始化增量，这里使用序列长度的一半

    while (dk >= 1)
    {
        // 从第dk个元素开始，依次插入前面已经排好序的子序列中
        for (int i = dk; i < L.size(); i++) {
            int end = L[i]; // 取出当前元素
            int key = i - dk; // 获取待插入位置

            // 如果待插入位置在已排序序列中，并且待插入元素比当前元素大，就将当前元素后移

            while (key >= 0 && L[key] > end)
            {
                L[key + dk] = L[key]; // 将当前元素后移
                key -= dk; // 再次获取待插入位置
                moves++; // 记录移动次数
                comparisons++; // 记录比较次数
            }

            // 插入当前元素
            L[key + dk] = end;
            moves++; // 记录移动次数
        }
        dk /= 2; // 减小增量
    }
}




double measureSortingTime1(vector<int> arr, long long int& moves, long long int& comparisons)
{
    auto start = chrono::high_resolution_clock::now();
    shellsort(arr, moves, comparisons);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
    return duration.count(); // 返回执行时间（秒）
}

