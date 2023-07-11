#include <iostream>
#include <vector>
#include<string>
#include<cmath>
using namespace std;
// 获取数字的位数
int getDigit(int number, int digit)
{
    int divider = 1;
    for (int i = 0; i < digit; i++)
    {
        divider *= 10;
    }
    return (number / divider) % 10;
}//准确来说，这个函数实现了获取指定位数上的数字，例如123456，digit=1,函数返回5。

/*
// 获取数字的第n位（从右往左，从0开始）
int getDigit(int num, int n)
{
    int base = pow(10, n);
    return (num / base) % 10;
}
*/

// 基数排序
void radixSort(vector<int>& nums)
{
    int maxNum = *max_element(nums.begin(), nums.end());  // 获取序列中的最大值
    int maxDigit = to_string(maxNum).length();  // 最大值的位数
    /*
    to_string()函数通常用于将其他数据类型（例如整数、浮点数）转换为字符串。
    */
    //int maxDigit=static_cast<int>(log10(maxNum))+1;
    //
    for (int i = 0; i < maxDigit; i++)
    {
        vector<vector<int>> buckets(10);  // 创建10个桶
        //每次按照数字位数排序时，都要重新分配空间
        // 将数字分配到对应的桶中
        for (int num : nums)
        {
            int digit = getDigit(num, i);
            buckets[digit].push_back(num);
        }
        // 按照桶的顺序将数字合并
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

    cout << endl << "排序结果：";
    for (int num : nums)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
