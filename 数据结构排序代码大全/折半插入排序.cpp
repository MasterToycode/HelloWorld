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


//插入排序算法
void Insertsort(int*& L)
{
    int i = 0;
    //从第二个数开始遍历
    for (i = 1; i < 8; i++)
    {
        int end = *(L + i); //获取当前要插入的数
        int low = 0;
        int high = i - 1;
        //使用二分查找法，找到插入位置
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (*(L + mid) > end)high = mid - 1; //如果中间值大于当前数，则缩小查找区间
            else low = mid + 1; //说明在上半区
        }//当high<low时，说明插入位置在low这里
        //将插入位置后的数往后移一位
        for (int j = i - 1; j >= high + 1; j--)
        {
            *(L + j + 1) = *(L + j);
        }
        //将当前数插入到对应位置
        *(L + high + 1) = end;
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
    Insertsort(L);
    ouput(L);
}