#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item
{
    int price; // 物品的价值
    int weight; // 物品的重量
};

// 动态规划版本的分数背包问题函数
int FractionalKnapsackDP(vector<Item>& items, int capacity) {
    int n = items.size();
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    // 动态规划的状态转移
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= capacity; j++) {
            if (items[i - 1].weight <= j) {
                // 当前物品可以放入背包
                // 比较选择放入当前物品和不放入当前物品的两种方案，取总价值较大的方案
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - items[i - 1].weight] + items[i - 1].price);
            }
            else {
                // 当前物品无法放入背包，保持前一个状态的值不变
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    // 返回背包中物品的最大总价值
    return dp[n][capacity];
}

int main() {
    vector<Item> items = { {60, 10}, {100, 20}, {120, 30} };
    int capacity = 50;

    // 调用动态规划函数，获取背包中物品的最大总价值
    int maxPrice = FractionalKnapsackDP(items, capacity);

    // 输出结果
    cout << "背包中物品的最大总价格为：" << maxPrice << endl;

    return 0;
}
