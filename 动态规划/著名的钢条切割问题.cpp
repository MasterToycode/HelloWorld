#include<iostream>
#include<vector>
#include <algorithm>
#include<climits>
using namespace std;
// 定义函数 Fun1，接收参数：一个数组 r，一个整数 n，两个引用型数组 p 和 s
int Fun1(vector<int>r, int n, vector<int>& p, vector<int>& s)
{
    int q = 0;  // 定义变量 q，初始化为 0
    if (p[n] >= 0)  // 如果数组 p 的第 n 项大于等于 0，则返回数组 p 的第 n 项
        return p[n];
    else if (n == 0)  // 如果 n 等于 0，则 q 为 0，s 的第 n 项为 0
    {
        q = 0;
        s[n] = 0;
    }
    else  // 否则
    {
        q = INT16_MIN;  // 将 q 初始化为最小值（16 位整数的最小值）
        int i = 0;  // 定义变量 i，初始化为 0
        for (i = 1; i <= n; i++)  // 循环 i，从 1 到 n
        {
            int temp = max(q, r[i] + Fun1(r, n - i, p, s));  // 计算 temp，即 q 和 r[i] + Fun1(r, n - i, p, s) 的较大值
            if (temp > q)  // 如果 temp 大于 q，则更新 q 和 s 的第 n 项为 i
            {
                q = temp;
                s[n] = i;
            }
        }
    }
    p[n] = q;  // 将 q 赋值给数组 p 的第 n 项

    return q;  // 返回 q
}  // 动态规划算法的实现



// 定义函数 fun，传入参数为一个整型向量 r 和一个整型 n
void fun(vector<int> r, int n)
{
    // 定义两个整型向量 p 和 s，长度为 n+1
    vector<int> p(n + 1);
    vector<int> s(n + 1);
    // 初始化 p 和 s 的所有元素为 INT16_MIN
    for (int i = 0; i <= n; i++)
    {
        p[i] = INT16_MIN;
        s[i] = INT16_MIN;
    }
    // 调用函数 Fun1，传入参数为向量 r、整数 n、向量 p 和向量 s，将返回值保存在整数变量 a 中
    int a = Fun1(r, n, p, s);
    // 输出切割方案
    cout << "切割方案为：";
    while (n > 0)
    {
        cout << s[n] << " ";
        n -= s[n];
    }
    cout << endl;
    // 输出钢条切割之后的最大价格
    cout << "钢条切割之后的最大价格为：" << a << endl;
}


int main()
{
	int n;
	cout << "请输入您的钢条总长度" << endl;
	cin >> n;
	vector<int>r = { 0,1,5,8,9,10,17,17,20,24,30 };
	//数组中存储的是从0到10的长度，
	//单根钢条对应的价格
	fun(r, n);
}