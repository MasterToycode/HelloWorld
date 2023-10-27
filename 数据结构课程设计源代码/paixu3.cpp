#include"h1.h"
// ��������ĺ����㷨�������з�Ϊ�����֣���߱����ĵ�С���ұ߱����ĵ��
int Quick_Sort(vector<int>& L, int low, int high, long long int& moves, long long int& comparisons)
{
    // �Ե�һ��Ԫ��Ϊ���ĵ�
    int key = L[low];
    while (low < high)
    {
        // ���������ҵ���һ�������ĵ�С��Ԫ��
        while (low < high && L[high] >= key)
        {
            high--;
            comparisons++;
        }
        // ����Ԫ�طŵ����ĵ����
        L[low] = L[high];
        moves++;

        // ���������ҵ���һ�������ĵ���Ԫ��
        while (low < high && L[low] <= key)
        {
            low++;
            comparisons++;
        }
        // ����Ԫ�طŵ����ĵ��ұ�
        L[high] = L[low];
        moves++;
    }
    // �����ĵ�ŵ�����λ��


    L[high] = key;
    moves++;
    // �������ĵ��λ��

    return low;
}


// ��������ĵݹ麯��
void QuickSort(vector<int>& L, int low, int high, long long int& moves, long long int& comparisons)
{
    if (low < high)
    {
        // �����з�Ϊ������
        int pivotloc = Quick_Sort(L, low, high, moves, comparisons);
        // ����벿�ֽ�������
        QuickSort(L, low, pivotloc - 1, moves, comparisons);
        // ���Ұ벿�ֽ�������
        QuickSort(L, pivotloc + 1, high, moves, comparisons);
    }
}


double measureSortingTime3(vector<int> arr, int low, int high, long long int& moves, long long int& comparisons)
{
    auto start = chrono::high_resolution_clock::now();
    QuickSort(arr, low, high, moves, comparisons);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
    return duration.count(); // ����ִ��ʱ�䣨�룩
}

