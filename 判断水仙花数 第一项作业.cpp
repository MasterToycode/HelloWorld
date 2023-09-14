#include<iostream>
#include<cmath>
using namespace std;
bool isNarcissistic(int num) //�ж��Ƿ�Ϊˮ�ɻ����ĺ���
{
    int originalNum = num; //����ԭʼֵ
    int numDigits = (int)log10(num) + 1; //ȷ�����ֵ�λ��
    int sum = 0; //���ڴ洢ÿ��λ�������ֵ� numDigits �η��ĺ�
    while (num > 0) //ѭ������ÿ������
    {
        int digit = num % 10; //ȡ�� num ��ÿ��λ���ϵ�λ��
        sum += pow(digit, numDigits); //����λ�������ֵ� numDigits �η����� sum
        num /= 10; 
    }
    return sum == originalNum; //�� sum ����ԭʼֵ���򷵻��棬���򷵻ؼ�
}

int main()
{
    cout << "������������" << endl;
    int num;
    cin >> num;
    if (isNarcissistic(num))
        cout << num << "��ˮ�ɻ���" << endl;
    else
        cout << num << "����ˮ�ɻ���" << endl;
    return 0;
}
