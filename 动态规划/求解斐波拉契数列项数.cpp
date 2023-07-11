#include <iostream>
#include <vector>
using namespace std;
int fibonacci(int n)
{
    std::vector<int> dp(n + 1); // ���ڴ洢������Ľ�

    // ��ʼ����
    dp[0] = 0;
    dp[1] = 1;

    // �ӵ����ϵ������������Ľ�
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n]; // ����ԭ����Ľ�
}

int main() {
    int n;
    cout << "��������Ҫ����쳲����������е�����" << endl;
    cin >> n;
    int long result = fibonacci(n);
    cout << "쳲��������е� " << n << " ��Ϊ��" << result << endl;
    return 0;
}

