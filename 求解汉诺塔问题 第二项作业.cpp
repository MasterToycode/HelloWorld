#include <iostream>
using namespace std;
// ����ݹ麯����ʵ�ֺ�ŵ���ƶ��Ĺ���
void hanoi(int n, char source, char auxiliary, char target) {
    // ���ֻ��һ�����ӣ�ֱ�ӽ����Դ���ƶ���Ŀ���
    if (n == 1) {
        cout << "�ƶ����� " << n << " �� " << source << " �� " << target << std::endl;
        return;
    }
    // �� n-1 �����Ӵ�Դ���ƶ���������
    hanoi(n - 1, source, target, auxiliary);
    // ���� n �����Ӵ�Դ���ƶ���Ŀ���
    cout << "�ƶ����� " << n << " �� " << source << " �� " << target << std::endl;
    // �� n-1 �����ӴӸ������ƶ���Ŀ���
    hanoi(n - 1, auxiliary, source, target);
}

int main() {
    int n;
    cout << "���������ӵ�������";
    cin >> n;
    hanoi(n, 'A', 'B', 'C');
    return 0;
}
