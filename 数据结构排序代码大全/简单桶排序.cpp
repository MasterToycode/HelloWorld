#include <iostream>
#include <vector>
using namespace std;
// Ͱ�����㷨ʵ��
void bucketSort(vector<int>& nums, int maxVal)
{
    // ����һ��Ͱ���飬��ʼ��Ϊ��
    vector<int> buckets(maxVal + 1, 0);

    // �����ݷ����Ӧ��Ͱ��
    for (int num : nums)
    {
        buckets[num]++;
    }//Ŀ���ǽ���Ҫ���������Ͱ�б��
    //��������nums�����е�һ��Ԫ��ʱ������Ӧ��Ͱ������1��
    //ͳ��ÿ��Ԫ�صĳ��ִ���

    // ��˳��ȡ��Ͱ�е����ݣ���������ԭ����
    int index = 0;
    for (int i = 0; i <= maxVal; i++)
    {
        while (buckets[i] > 0)
        {
            nums[index++] = i;
            buckets[i]--;
        }
    }
}

// ����ע�ͣ�
// ������
// nums�������������
// maxVal�����������ֵ
// ʵ�ֲ��裺
// 1. ����һ��Ͱ���飬��ʼ��Ϊ��
// 2. �����ݷ����Ӧ��Ͱ��
// 3. ��˳��ȡ��Ͱ�е����ݣ���������ԭ����
// 4. ʱ�临�Ӷ�ΪO(n)���ռ临�Ӷ�ΪO(maxVal + 1)

int main()
{
    vector<int> nums(8, 0);
    for (int i = 0; i < 8; i++)
    {
        cin >> nums[i];
    }

    int maxVal = 97;  // ���ֵΪ���������е����ֵ

    bucketSort(nums, maxVal);

    // ��������Ľ��
    for (int num : nums)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}