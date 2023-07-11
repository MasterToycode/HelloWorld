#include<iostream>
using namespace std;

void input(int*& L)
{
    int i = 0;
    for (i = 0; i < 8; i++)
    {
        cin >> *(L + i);
    }
}

// 希尔排序，对L进行排序，以a数组为增量序列
void shellsort(int*& L, int dk)
{
    // 从第dk个元素开始，依次插入前面已经排好序的子序列中
    for (int i = dk; i < 8; i++)
    {
        int end = *(L + i); // 取出当前元素
        int key = i - dk; // 获取待插入位置
        // 如果待插入位置在已排序序列中，并且待插入元素比当前元素大，就将当前元素后移
        while (key >= 0 && *(L + key) > end)
        {
            *(L + key + dk) = *(L + key); // 将当前元素后移
            key -= dk; // 再次获取待插入位置
        }
        // 插入当前元素
        *(L + key + dk) = end;
    }
}

// 希尔排序，对L进行排序，以a数组为增量序列
void ShellInsert(int*& L, int a[])
{
    int t = 0;
    // 遍历增量序列
    for (t = 0; t < 4; t++)
    {
        shellsort(L, a[t]); // 对L进行排序，以a[t]为增量
    }
}







void ouput(int*& L)
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
    int a[4] = { 5,3,2,1 };
    ShellInsert(L, a);
    ouput(L);
}