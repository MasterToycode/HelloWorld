#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item
{
    int price; // ��Ʒ�ļ�ֵ
    int weight; // ��Ʒ������
};

// ��̬�滮�汾�ķ����������⺯��
int FractionalKnapsackDP(vector<Item>& items, int capacity) {
    int n = items.size();
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    // ��̬�滮��״̬ת��
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= capacity; j++) {
            if (items[i - 1].weight <= j) {
                // ��ǰ��Ʒ���Է��뱳��
                // �Ƚ�ѡ����뵱ǰ��Ʒ�Ͳ����뵱ǰ��Ʒ�����ַ�����ȡ�ܼ�ֵ�ϴ�ķ���
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - items[i - 1].weight] + items[i - 1].price);
            }
            else {
                // ��ǰ��Ʒ�޷����뱳��������ǰһ��״̬��ֵ����
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    // ���ر�������Ʒ������ܼ�ֵ
    return dp[n][capacity];
}

int main() {
    vector<Item> items = { {60, 10}, {100, 20}, {120, 30} };
    int capacity = 50;

    // ���ö�̬�滮��������ȡ��������Ʒ������ܼ�ֵ
    int maxPrice = FractionalKnapsackDP(items, capacity);

    // ������
    cout << "��������Ʒ������ܼ۸�Ϊ��" << maxPrice << endl;

    return 0;
}
