#include<iostream>
#include<vector>
#include <algorithm>
#include<climits>
using namespace std;
// ���庯�� Fun1�����ղ�����һ������ r��һ������ n���������������� p �� s
int Fun1(vector<int>r, int n, vector<int>& p, vector<int>& s)
{
    int q = 0;  // ������� q����ʼ��Ϊ 0
    if (p[n] >= 0)  // ������� p �ĵ� n ����ڵ��� 0���򷵻����� p �ĵ� n ��
        return p[n];
    else if (n == 0)  // ��� n ���� 0���� q Ϊ 0��s �ĵ� n ��Ϊ 0
    {
        q = 0;
        s[n] = 0;
    }
    else  // ����
    {
        q = INT16_MIN;  // �� q ��ʼ��Ϊ��Сֵ��16 λ��������Сֵ��
        int i = 0;  // ������� i����ʼ��Ϊ 0
        for (i = 1; i <= n; i++)  // ѭ�� i���� 1 �� n
        {
            int temp = max(q, r[i] + Fun1(r, n - i, p, s));  // ���� temp���� q �� r[i] + Fun1(r, n - i, p, s) �Ľϴ�ֵ
            if (temp > q)  // ��� temp ���� q������� q �� s �ĵ� n ��Ϊ i
            {
                q = temp;
                s[n] = i;
            }
        }
    }
    p[n] = q;  // �� q ��ֵ������ p �ĵ� n ��

    return q;  // ���� q
}  // ��̬�滮�㷨��ʵ��



// ���庯�� fun���������Ϊһ���������� r ��һ������ n
void fun(vector<int> r, int n)
{
    // ���������������� p �� s������Ϊ n+1
    vector<int> p(n + 1);
    vector<int> s(n + 1);
    // ��ʼ�� p �� s ������Ԫ��Ϊ INT16_MIN
    for (int i = 0; i <= n; i++)
    {
        p[i] = INT16_MIN;
        s[i] = INT16_MIN;
    }
    // ���ú��� Fun1���������Ϊ���� r������ n������ p ������ s��������ֵ�������������� a ��
    int a = Fun1(r, n, p, s);
    // ����и��
    cout << "�и��Ϊ��";
    while (n > 0)
    {
        cout << s[n] << " ";
        n -= s[n];
    }
    cout << endl;
    // ��������и�֮������۸�
    cout << "�����и�֮������۸�Ϊ��" << a << endl;
}


int main()
{
	int n;
	cout << "���������ĸ����ܳ���" << endl;
	cin >> n;
	vector<int>r = { 0,1,5,8,9,10,17,17,20,24,30 };
	//�����д洢���Ǵ�0��10�ĳ��ȣ�
	//����������Ӧ�ļ۸�
	fun(r, n);
}