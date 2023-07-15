#include<iostream>
#include<vector>
#include<climits> // 包含 INT_MAX 和 INT_MIN
using namespace std;

// 辅助递归函数，返回 s[n1:n2] 中最大相互兼容活动组合的数量
int Fun_activity(vector<int>& s, vector<int>& f, int n1, int n2, vector<vector<int>>& m)
{
    if (m[n1][n2] != -1) // 如果已经计算过，直接返回结果
    {
        return m[n1][n2];
    }
    else if (n1 + 1 == n2) // 基本情况：只有一个活动
    {
        m[n1][n2] = 1; // 只有一个活动时，最大相互兼容活动组合的数量为 1
        return 1;
    }
    else // 递归情况
    {
        int maxCount = 0;
        for (int i = n1 + 1; i < n2; i++) // 枚举中间的活动
        {
            if (f[n1] <= s[i] && f[i] <= s[n2])  // 检查活动的兼容性
            {
                // 计算左右两边的最大相互兼容活动组合的数量，并取最大值
                maxCount = max(maxCount, Fun_activity(s, f, n1, i, m) + Fun_activity(s, f, i, n2, m) + 1);
            }
        }
        m[n1][n2] = maxCount; // 记录结果
        return m[n1][n2];
    }
}

void GetMaxCompatibilities(vector<int>& s, vector<int>& f)
{
    int n = s.size();
    vector<vector<int>> m(n, vector<int>(n, -1)); // 初始化备忘录矩阵，全部赋值为 -1
    cout << "最大相互兼容活动组合的数量为：" << Fun_activity(s, f, 0, n - 1, m) << endl;
}

int main()
{
    vector<int> s = { 0, 1, 3, 0, 5, 3, 5, 6, 8, 8, 2, 12 };
    vector<int> f = { 0, 4, 5, 6, 7, 9, 9, 10, 11, 12, 14, 16 };
    GetMaxCompatibilities(s, f);
    cout << endl;
    return 0;
}
