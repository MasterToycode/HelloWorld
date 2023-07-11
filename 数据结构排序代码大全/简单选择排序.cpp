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


//选择排序，每次找到未排序序列中最小的元素，放到已排序序列的末尾
int SelectMinkey(int* L, int n)//选择未排序序列中最小的元素的下标
{
    int key = n;
    for (int i = n + 1; i < 7; i++)
    {
        if (L[key] > L[i])
            key = i;
    }
    return key;
}



void SelectionSort(int* L)//选择排序
{
    for (int i = 0; i < 6; i++)
    {
        int j = SelectMinkey(L, i);//找到未排序序列中最小元素的下标
        if (i != j)//如果未排序序列中最小元素不在已排序序列的末尾，则交换它们的位置
        {
            int temp = L[i];
            L[i] = L[j];
            L[j] = temp;
        }
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
    SelectionSort(L);
    ouput(L);
}