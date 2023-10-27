#include"h1.h"
void Insertsort(vector<int>& L, long long int& moves, long long int& comparisons)
{
    int i = 0;
    //�ӵڶ�������ʼ����
    for (i = 1; i < L.size(); i++)
    {
        int end = L[i]; //��ȡ��ǰҪ�������
        int low = 0;
        int high = i - 1;
        //ʹ�ö��ֲ��ҷ����ҵ�����λ��


        while (low <= high)
        {
            int mid = (low + high) / 2;
            comparisons++;//ʵ�����ӵıȽϴ�����һ���������ȡ��һ���У�
            if (L[mid] > end)
            {
                high = mid - 1;
            } //����м�ֵ���ڵ�ǰ��������С��������
            else
            {
                low = mid + 1;
            }
            //˵�����ϰ���


        }//��high<lowʱ��˵������λ����low����

         //������λ�ú����������һλ

        for (int j = i - 1; j >= high + 1; j--)
        {
            L[j + 1] = L[j];
            moves++;
        }
        //����ǰ�����뵽��Ӧλ��

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
    return duration.count(); // ����ִ��ʱ�䣨�룩
}

