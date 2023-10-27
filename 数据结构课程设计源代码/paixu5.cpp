#include"h1.h"
void Insertsort(vector<int>& L, long long int& moves, long long int& comparisons)
{
    int i = 0;
    //从第二个数开始遍历
    for (i = 1; i < L.size(); i++)
    {
        int end = L[i]; //获取当前要插入的数
        int low = 0;
        int high = i - 1;
        //使用二分查找法，找到插入位置


        while (low <= high)
        {
            int mid = (low + high) / 2;
            comparisons++;//实际增加的比较次数！一下两种情况取其一就行！
            if (L[mid] > end)
            {
                high = mid - 1;
            } //如果中间值大于当前数，则缩小查找区间
            else
            {
                low = mid + 1;
            }
            //说明在上半区


        }//当high<low时，说明插入位置在low这里

         //将插入位置后的数往后移一位

        for (int j = i - 1; j >= high + 1; j--)
        {
            L[j + 1] = L[j];
            moves++;
        }
        //将当前数插入到对应位置

        L[high + 1] = end;
        moves++;
    }
}


double measureSortingTime5(vector<int> arr, long long int& moves, long long int& comparisons)
{
    auto start = chrono::high_resolution_clock::now();
    Insertsort(arr, moves, comparisons);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
    return duration.count(); // 返回执行时间（秒）
}

