#include"h1.h"
void swap(int& a, int& b)
{
    int c = a;
    a = b;
    b = c;
}
// �ѵ�������������sΪ������������ΪС����
void HeapAdjust(vector<int>& L, int s, int m, long long int& moves, long long int& comparisons)
{
    // ���浱ǰ���ڵ��ֵ
    int cr = L[s];
    // �����ӽڵ㿪ʼ����
    for (int i = 2 * s + 1; i <= m; i = 2 * i + 1)
    {
        // �ҳ������ӽڵ���ֵ��С�Ľڵ�
        if (i < m && L[i] > L[i + 1])
        {
            i++;
            comparisons++;// ��¼�Ƚϴ���
        }

        // �����ǰ���ڵ��Ѿ�С�ڵ����ӽڵ㣬������ѭ��
        if (cr <= L[i]) break;


        // ���ӽڵ�����
        L[s] = L[i];
        // ���µ�ǰ���ڵ��λ��
        s = i;
        moves++;//��¼�ƶ�����
    }

    // ��ԭ���ĸ��ڵ�ŵ��µ�λ����
    L[s] = cr;
}



// ��������
void HeapSort(vector<int>& L, int len, long long int& moves, long long int& comparisons)
{
    // ������ʼ��
    for (int i = len / 2 - 1; i >= 0; i--) // �����һ����Ҷ�ӽڵ㿪ʼ������
        HeapAdjust(L, i, len - 1, moves, comparisons); // �����ѽṹ
    // ���Ѷ�Ԫ����ѵ�Ԫ�ؽ����������µ�����


    for (int i = len - 1; i >= 0; i--) // �ѵĴ�Сÿ�μ�1
    {
        //cout << L[0] << " "; // ����Ѷ�Ԫ��
        if (i) // ���ѵĴ�С��Ϊ0ʱ�����н����͵�����
        {
            swap(L[0], L[i]); // ���Ѷ�Ԫ����ѵ�Ԫ�ؽ���

            moves++;//��¼�ƶ�������

            HeapAdjust(L, 0, i - 1, moves, comparisons); // �����ѽṹ
        }
    }
}



double measureSortingTime2(vector<int> arr, int len, long long int& moves, long long int& comparisons)
{
    auto start = chrono::high_resolution_clock::now();
    HeapSort(arr, len, moves, comparisons);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
    return duration.count(); // ����ִ��ʱ�䣨�룩
}

