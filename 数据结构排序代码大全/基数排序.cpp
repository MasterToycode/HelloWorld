#include <iostream>
#include <vector>
#include<string>
#include<cmath>
using namespace std;
// ��ȡ���ֵ�λ��
int getDigit(int number, int digit)
{
    int divider = 1;
    for (int i = 0; i < digit; i++)
    {
        divider *= 10;
    }
    return (number / divider) % 10;
}//׼ȷ��˵���������ʵ���˻�ȡָ��λ���ϵ����֣�����123456��digit=1,��������5��

/*
// ��ȡ���ֵĵ�nλ���������󣬴�0��ʼ��
int getDigit(int num, int n)
{
    int base = pow(10, n);
    return (num / base) % 10;
}
*/

// ��������
void radixSort(vector<int>& nums)
{
    int maxNum = *max_element(nums.begin(), nums.end());  // ��ȡ�����е����ֵ
    int maxDigit = to_string(maxNum).length();  // ���ֵ��λ��
    /*
    to_string()����ͨ�����ڽ������������ͣ�������������������ת��Ϊ�ַ�����
    */
    //int maxDigit=static_cast<int>(log10(maxNum))+1;
    //
    for (int i = 0; i < maxDigit; i++)
    {
        vector<vector<int>> buckets(10);  // ����10��Ͱ
        //ÿ�ΰ�������λ������ʱ����Ҫ���·���ռ�
        // �����ַ��䵽��Ӧ��Ͱ��
        for (int num : nums)
        {
            int digit = getDigit(num, i);
            buckets[digit].push_back(num);
        }
        // ����Ͱ��˳�����ֺϲ�
        int index = 0;
        for (auto& bucket : buckets)
        {
            for (int num : bucket)
            {
                nums[index++] = num;
            }
        }
    }
}

int main()
{
    vector<int> nums(8, 0);
    for (int i = 0; i < 8; i++)
    {
        cin >> nums[i];
    }
    radixSort(nums);

    cout << endl << "��������";
    for (int num : nums)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
