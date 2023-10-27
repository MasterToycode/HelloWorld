#include"h1.h"
void shellsort(vector<int>& L, long long int& moves, long long int& comparisons)
{
    int dk = L.size() / 2; // ��ʼ������������ʹ�����г��ȵ�һ��

    while (dk >= 1)
    {
        // �ӵ�dk��Ԫ�ؿ�ʼ�����β���ǰ���Ѿ��ź������������
        for (int i = dk; i < L.size(); i++) {
            int end = L[i]; // ȡ����ǰԪ��
            int key = i - dk; // ��ȡ������λ��

            // ���������λ���������������У����Ҵ�����Ԫ�رȵ�ǰԪ�ش󣬾ͽ���ǰԪ�غ���

            while (key >= 0 && L[key] > end)
            {
                L[key + dk] = L[key]; // ����ǰԪ�غ���
                key -= dk; // �ٴλ�ȡ������λ��
                moves++; // ��¼�ƶ�����
                comparisons++; // ��¼�Ƚϴ���
            }

            // ���뵱ǰԪ��
            L[key + dk] = end;
            moves++; // ��¼�ƶ�����
        }
        dk /= 2; // ��С����
    }
}




double measureSortingTime1(vector<int> arr, long long int& moves, long long int& comparisons)
{
    auto start = chrono::high_resolution_clock::now();
    shellsort(arr, moves, comparisons);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
    return duration.count(); // ����ִ��ʱ�䣨�룩
}

