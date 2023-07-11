#include <iostream>
#include <vector>
using namespace std;
// 桶排序算法实现
void bucketSort(vector<int>& nums, int maxVal)
{
    // 创建一个桶数组，初始化为空
    vector<int> buckets(maxVal + 1, 0);

    // 将数据放入对应的桶中
    for (int num : nums)
    {
        buckets[num]++;
    }//目的是将需要排序的数在桶中标记
    //当遍历到nums向量中的一个元素时，将对应的桶计数加1。
    //统计每个元素的出现次数

    // 按顺序取出桶中的数据，重新排序原数组
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

// 代码注释：
// 参数：
// nums：待排序的数组
// maxVal：数组中最大值
// 实现步骤：
// 1. 创建一个桶数组，初始化为空
// 2. 将数据放入对应的桶中
// 3. 按顺序取出桶中的数据，重新排序原数组
// 4. 时间复杂度为O(n)，空间复杂度为O(maxVal + 1)

int main()
{
    vector<int> nums(8, 0);
    for (int i = 0; i < 8; i++)
    {
        cin >> nums[i];
    }

    int maxVal = 97;  // 最大值为给定数据中的最大值

    bucketSort(nums, maxVal);

    // 输出排序后的结果
    for (int num : nums)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}