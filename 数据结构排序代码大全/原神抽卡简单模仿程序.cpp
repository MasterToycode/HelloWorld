#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));  // �������������Ϊ��ǰʱ��

    int totalEvents;  // Ҫ���еĳ齱����

    cout << "������Ҫ���еĳ齱����: ";
    cin >> totalEvents;

    cout << "�齱��ʼ��" << endl;

    for (int event = 1; event <= totalEvents; event++) {
        int currentAttempt = 1;  // ��ǰ�齱����
        double probability = 0.006; // ��ǰ����A��B�ĸ��ʣ���ʼΪ0.6%

        cout << "�� " << event << " �γ齱��" << endl;

        while (currentAttempt <= 90) {
            int randomNumber = rand() % 1000 + 1;  // ����1��1000֮��������

            if (randomNumber <= probability * 1000) {
                if (randomNumber % 2 == 0) {
                    cout << "�� " << currentAttempt << " �γ齱����ϲ����������Ʒ A��" << endl;
                }
                else {
                    cout << "�� " << currentAttempt << " �γ齱����ϲ����������Ʒ B��" << endl;
                }
                break;
            }
            else {
                cout << "�� " << currentAttempt << " �γ齱�����ź�û�г����κ���Ʒ��" << endl;
            }

            if (currentAttempt == 70) {
                // �ӵ�71�ο�ʼ���ʵ���6%
                probability = 0.006;
            }
            else if (currentAttempt > 70) {
                // ÿ�ε���6%
                probability += 0.00006;
                if (probability > 0.99) {
                    probability = 0.99;  // ȷ�����ʲ�����99%
                }
            }

            currentAttempt++;
        }

        if (currentAttempt > 90) {
            cout << "�齱�����Ѵﵽ90�Σ��˳��齱��" << endl;
            break;
        }
    }

    cout << "�齱������" << endl;

    return 0;
}