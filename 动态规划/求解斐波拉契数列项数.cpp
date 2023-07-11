#include <iostream>
#include <vector>
using namespace std;
int fibonacci(int n)
{
    std::vector<int> dp(n + 1); // 用于存储子问题的解

    // 初始条件
    dp[0] = 0;
    dp[1] = 1;

    // 从底向上迭代求解子问题的解
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n]; // 返回原问题的解
}

int main() {
    int n;
    cout << "输入您想要求解的斐波那契数列中的项数" << endl;
    cin >> n;
    int long result = fibonacci(n);
    cout << "斐波那契数列第 " << n << " 项为：" << result << endl;
    return 0;
}

