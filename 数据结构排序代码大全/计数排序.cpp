#include<iostream>
using namespace std;
void input(int*& L)
{
    int i = 0;
    for (i = 1; i < 9; i++)
    {
        cin >> *(L + i);
    }
}






void output(int*& L)
{
    int i = 0;
    for (i = 1; i < 9; i++)
    {
        cout << *(L + i) << " ";
    }
    cout << endl;
}






void COUNTING_SORT(int*& L, int*& C) //定义计数排序函数
{
    int i = 0;
    int* A = new int[98]; //定义计数数组，下标为元素值减1，因为元素值最小为1，而数组下标从0开始
    for (int i = 0; i < 98; i++) //初始化计数数组为0
    {
        *(A + i) = 0;
    }
    for (i = 1; i < 9; i++)
    {
        *(A + *(L + i)) = *(A + *(L + i)) + 1; //将元素值出现次数记录到计数数组中
    }//现在的辅助数组保存的是A[L[i]]保存着等于L[i]的元素的个数
    for (i = 1; i < 98; i++) //计算每个元素值最终在输出数组中的位置
    {
        *(A + i) = *(A + i) + *(A + i - 1);
    }//现在的辅助数组保存的是A[L[i]]保存着小于等于L[i]的元素的个数
    for (i = 8; i >= 1; i--) //将元素按照计数数组中记录的位置放入输出数组中
    {
        *(C + *(A + *(L + i))) = *(L + i);
        *(A + *(L + i)) = *(A + *(L + i)) - 1;
    }
}//需要注意的是：所有数组分配的空间需要多一个，且排序数组中，第一个位置没有使用。





int main()
{
    int* L = new int[9];
    input(L);
    int* A = new int[9];
    COUNTING_SORT(L, A);
    output(A);
    cout << endl;
}